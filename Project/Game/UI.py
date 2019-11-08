import ge

class UI:
	def __init__(self, gameOb, eng, val, baseText):
		self.gameObject = gameOb
		self.engine = eng
		self.text = self.gameObject.getTextComponent()
		self.transform = self.gameObject.getTransform()
		self.text.setActive(True)
		print(self.transform.getX())
		self.val = val
		self.text.setText(baseText + str(val))
		

	def render(self):
		x = int(self.transform.getX())
		y = int(self.transform.getY())
		r = self.transform.getRotate()
		self.text.render(x,y,r,ge.ImgFlip.NONE)

	def updateText(self,newText):
		self.text.setText(newText)
	def update(self, baseText, val):
		if(val != self.val):
			self.val = val
			self.updateText(baseText + str(val))