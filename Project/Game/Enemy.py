import ge
import random
class Enemy:
	def __init__(self, gameOb, eng):
		self.gameObject = gameOb
		self.engine = eng
		self.transform = self.gameObject.getTransform()
		self.collider = self.gameObject.getCollider()
		self.img = self.gameObject.getImageComponent()


		newX = random.randint(0,650)
		self.transform.setX(newX)

		newY = random.randint(0,250) * -1
		self.transform.setY(newY)

	def render(self):
		self.gameObject.render(ge.ImgFlip.NONE)
