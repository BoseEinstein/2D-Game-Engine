import ge

class Projectile:
	def __init__(self, gameOb, eng, vel):
		self.gameObject = gameOb
		self.engine = eng
		self.transform = self.gameObject.getTransform()
		self.collider = self.gameObject.getCollider()
		self.text = self.gameObject.getTextComponent()
		self.text.setActive(False)
		self.vel = vel
	def update(self):
		if self.gameObject.isActive():
			newY = self.transform.getY() + self.vel
			self.transform.setY(newY)
			if(newY > 744 or newY < 0):
				self.deactivate()

	def resetAt(self,x,y):
		#print("Fired Missile")
		self.gameObject.setActive(True)
		self.transform.setX(x)
		self.transform.setY(y - self.collider.getHeight())

	def deactivate(self):
		self.gameObject.setActive(False)
	def render(self):
		self.gameObject.render(ge.ImgFlip.NONE)

