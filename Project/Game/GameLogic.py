#Assets From https://ansimuz.itch.io/spaceship-shooter-environment
class GameLogic:
	def __init__(self):
		self.lives = 3
		self.screenWidth = 700
		self.screenHeight = 744
		self.score = 0

	def get_score(self):
		return self.score

	def get_lives(self):
		return self.lives;

	def change_score(self,val):
		self.score = self.score + val

	def change_lives(self,val):
		self.lives = self.lives + val

	def is_game_over(self):
		return self.lives <= 0
	def reset(self):
		self.lives = 3
		self.score = 0
