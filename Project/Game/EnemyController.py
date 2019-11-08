import ge
import random
class EnemyController:



	def __init__(self, enemies, enemyLasers):
		self.enemies = enemies
		self.enemyLasers = enemyLasers
		self.ship_speed = 2


	def getEnemies(self):
		return self.enemies
	def getEnemyLasers(self):
		return self.enemyLasers

	def resetShip(self, ship):
		newX = random.randint(0,650)
		ship.transform.setX(newX)
		ship.transform.setY(-ship.collider.getHeight())

	def reset(self):
		for s in self.enemies:
			self.resetShip(s)
		for l in self.enemyLasers:
			l.deactivate()

	def moveShips(self):
		for i in range(5):
			s = self.enemies[i]
			newY = s.transform.getY() + self.ship_speed
			s.transform.setY(newY)
			if(newY > 744):
				self.resetShip(s)
			if not self.enemyLasers[i].gameObject.isActive():
				if s.transform.getY() > 10:
					self.enemyLasers[i].resetAt(s.transform.getX(),s.transform.getY())


	def moveLaser(self):
		for l in self.enemyLasers:
			l.update()

	def update(self):
		self.moveShips()
		self.moveLaser()

	def render(self):

		for s in self.enemies:
			s.render()

		for l in self.enemyLasers:
			l.render()
