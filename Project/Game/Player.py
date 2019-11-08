import ge

class Player:

	

	def __init__(self, gameOb, eng, lasers):
		self.gameObject = gameOb
		self.engine = eng
		self._input = self.engine.getInputSystem()
		self.transform = gameOb.getTransform()
		self.collider = gameOb.getCollider()
		print(self.collider.getWidth())
		print(self.collider.getHeight())
		self.vel = 0
		self.lasers = lasers

	def render(self):
		self.gameObject.render(ge.ImgFlip.NONE)
		for l in self.lasers:
			l.render()
	


	def update(self, inputReceived, enemControl, gameRules):
		if inputReceived == "moveLeft":
			self.moveLeft()
		elif inputReceived == "moveRight":
			self.moveRight()
		elif inputReceived == "fire":
			self.fireLaser()
		elif inputReceived == "-moveLeft" or inputReceived == "-moveRight":
			#print("key released")
			self.vel = 0


		oldX = self.transform.getX()
		newX = oldX + self.vel

		if(newX >= 0 and newX + self.collider.getWidth() <= 700):
			self.transform.setX(newX)
		else:
			self.transform.setX(oldX)
			print("out of bounds")
		for l in self.lasers:
			l.update()

		enLasers = enemControl.getEnemyLasers()
		enems = enemControl.getEnemies()

		for en in enems:
			if self.gameObject.checkCollision(en.gameObject):
				enemControl.resetShip(en)
				gameRules.change_lives(-1)
				print("Hit ship")

		for en in enems:
			for l in self.lasers:
				if l.gameObject.checkCollision(en.gameObject):
					enemControl.resetShip(en)
					l.deactivate()
					gameRules.change_score(1)
					print("Hit ship")

		for el in enLasers:
			if self.gameObject.checkCollision(el.gameObject):
				gameRules.change_lives(-1)
				el.deactivate()
				print("Hit ship")


	def moveLeft(self):
		#print ("moving left")
		self.vel = -5
		

	def moveRight(self):
		#print ("moving Right")
		self.vel = 5

	def fireLaser(self):
		#print("Player Fire")
		for l in self.lasers:
			if not l.gameObject.isActive():
				l.resetAt(self.transform.getX(), self.transform.getY())
				break



