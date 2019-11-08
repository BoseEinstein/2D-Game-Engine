import Player
import Enemy
import ge
import EnemyController
import Projectile
import EnemyProjectile
import GameLogic
import UI


width = 700
height = 744
eng = ge.GameEngine(width,height)
bg = eng.addObject("background")
p = eng.addObject("player")
scoreText = eng.addObject("scoreText")
livesText = eng.addObject("livesText")
statusText = eng.addObject("statusText")
print("setting player and bg image")
bi = bg.getImageComponent()
bi.setImage("./Assets/images/desert-background.png")
bg.getAudioComponent().loadMusic("./Assets/music/breakout.mp3")
print("set bg")
pi = p.getImageComponent()
pi.setImage("./Assets/images/ship-solo.png")
pc = p.getCollider()
pc.setColliderSize(0,0,20,24)

sText = scoreText.getTextComponent()
sText.setText("Score: ");
lText = livesText.getTextComponent()
lText.setText("Lives: ")

st = scoreText.getTransform()
st.setX(0)
st.setY(0)

livt = livesText.getTransform()
livt.setY(0)
livt.setX(600)

stat_t = statusText.getTransform()
stat_t.setX(150)
stat_t.setY(350)

inSys = eng.getInputSystem()
inSys.registerInput("fire", ' ')
inSys.registerInput("moveLeft", 'a')
inSys.registerInput("moveRight", 'd')
inSys.registerInput("quit", 'w')




print("set player and bg")
t = p.getTransform()
t.setY(724)
print("setY")
print(t.getY())
t.setX(350)
print("setX")
print(p.getTransform().getX())

enemies = []
enemyLasers = []
playerLasers= []
explosions = []



e_name = "enemy0"
print(e_name)
enemies.append(eng.addObject(e_name))
print("enemy made")
enemies[0].setActive(True)
ec = enemies[0].getCollider()
ec.setColliderSize(0,0,32,16)
enemies[0].getTextComponent().setText("Enemy")
print("set enemy collider")
ei = enemies[0].getImageComponent()
ei.setImage("./Assets/images/enemy-solo.png")
print("set enemy image")
ei.setAnimationFrames(2,32,16,10,True)

e_name = "enemy1"
print(e_name)
enemies.append(eng.addObject(e_name))
print("enemy made")
enemies[1].setActive(True)
ec1 = enemies[1].getCollider()
ec1.setColliderSize(0,0,32,16)
enemies[1].getTextComponent().setText("Enemy")
print("set enemy collider")
ei0 = enemies[1].getImageComponent()
ei0.setImage("./Assets/images/enemy-solo.png")
print("set enemy image")
ei0.setAnimationFrames(2,32,16,10,True)

e_name = "enemy2"
print(e_name)
enemies.append(eng.addObject(e_name))
print("enemy made")
enemies[2].setActive(True)
ec2 = enemies[2].getCollider()
ec2.setColliderSize(0,0,32,16)
enemies[2].getTextComponent().setText("Enemy")
print("set enemy collider")
ei1 = enemies[2].getImageComponent()
ei1.setImage("./Assets/images/enemy-solo.png")
print("set enemy image")
ei1.setAnimationFrames(2,32,16,10,True)

e_name = "enemy3"
print(e_name)
enemies.append(eng.addObject(e_name))
print("enemy made")
enemies[3].setActive(True)
ec3 = enemies[3].getCollider()
ec3.setColliderSize(0,0,32,16)
enemies[3].getTextComponent().setText("Enemy")
print("set enemy collider")
ei2 = enemies[3].getImageComponent()
ei2.setImage("./Assets/images/enemy-solo.png")
print("set enemy image")
ei2.setAnimationFrames(2,32,16,10,True)

e_name = "enemy4"
print(e_name)
enemies.append(eng.addObject(e_name))
print("enemy made")
enemies[4].setActive(True)
ec4 = enemies[4].getCollider()
ec4.setColliderSize(0,0,32,16)
enemies[4].getTextComponent().setText("Enemy")
print("set enemy collider")
ei3 = enemies[4].getImageComponent()
ei3.setImage("./Assets/images/enemy-solo.png")
print("set enemy image")
ei3.setAnimationFrames(2,32,16,10,True)




lase_name = "enem_laser_0"
enemyLasers.append(eng.addObject(lase_name))
enemyLasers[0].setActive(False)
elc = enemyLasers[0].getCollider()
elc.setColliderSize(0,0,5,5)
#print("settting enem laser image")
li = enemyLasers[0].getImageComponent()
li.setImage("./Assets/images/enemy-shot.png")
#print("set lase img")
li.setAnimationFrames(2,5,5,5,True)
#print("set lase anim")


lase_name = "enem_laser_1"
enemyLasers.append(eng.addObject(lase_name))
enemyLasers[1].setActive(False)
elc1 = enemyLasers[1].getCollider()
elc1.setColliderSize(0,0,5,5)
#print("settting enem laser image")
li1 = enemyLasers[1].getImageComponent()
li1.setImage("./Assets/images/enemy-shot.png")
#print("set lase img")
li1.setAnimationFrames(2,5,5,5,True)


lase_name = "enem_laser_2"
enemyLasers.append(eng.addObject(lase_name))
enemyLasers[2].setActive(False)
elc2 = enemyLasers[2].getCollider()
elc2.setColliderSize(0,0,5,5)
#print("settting enem laser image")
li2 = enemyLasers[2].getImageComponent()
li2.setImage("./Assets/images/enemy-shot.png")
#print("set lase img")
li2.setAnimationFrames(2,5,5,5,True)


lase_name = "enem_laser_3"
enemyLasers.append(eng.addObject(lase_name))
enemyLasers[3].setActive(False)
elc3 = enemyLasers[3].getCollider()
elc3.setColliderSize(0,0,5,5)
#print("settting enem laser image")
li3 = enemyLasers[3].getImageComponent()
li3.setImage("./Assets/images/enemy-shot.png")
#print("set lase img")
li3.setAnimationFrames(2,5,5,5,True)


lase_name = "enem_laser_4"
enemyLasers.append(eng.addObject(lase_name))
enemyLasers[4].setActive(False)
elc4 = enemyLasers[4].getCollider()
elc4.setColliderSize(0,0,5,5)
#print("settting enem laser image")
li4 = enemyLasers[4].getImageComponent()
li4.setImage("./Assets/images/enemy-shot.png")
#print("set lase img")
li4.setAnimationFrames(2,5,5,5,True)
	

lase_name = "laser0"
playerLasers.append( eng.addObject(lase_name))
playerLasers[0].setActive(False)
lai = playerLasers[0].getImageComponent()
lai.setImage("./Assets/images/laser-bolts.png")
lai.setAnimationFrames(2,6,14,10,True)
plc = playerLasers[0].getCollider()
plc.setColliderSize(0,0,6,14)

lase_name = "laser1"
playerLasers.append( eng.addObject(lase_name))
playerLasers[1].setActive(False)
la1i = playerLasers[1].getImageComponent()
la1i.setImage("./Assets/images/laser-bolts.png")
la1i.setAnimationFrames(2,6,14,10,True)
plc1 = playerLasers[1].getCollider()
plc1.setColliderSize(0,0,6,14)

lase_name = "laser2"
playerLasers.append( eng.addObject(lase_name))
playerLasers[2].setActive(False)
la2i = playerLasers[2].getImageComponent()
la2i.setImage("./Assets/images/laser-bolts.png")
la2i.setAnimationFrames(2,6,14,10,True)
plc2 = playerLasers[2].getCollider()
plc2.setColliderSize(0,0,6,14)

lase_name = "laser3"
playerLasers.append( eng.addObject(lase_name))
playerLasers[3].setActive(False)
la3i = playerLasers[3].getImageComponent()
la3i.setImage("./Assets/images/laser-bolts.png")
la3i.setAnimationFrames(2,6,14,10,True)
plc3 = playerLasers[3].getCollider()
plc3.setColliderSize(0,0,6,14)

lase_name = "laser4"
playerLasers.append( eng.addObject(lase_name))
playerLasers[4].setActive(False)
la4i = playerLasers[4].getImageComponent()
la4i.setImage("./Assets/images/laser-bolts.png")
la4i.setAnimationFrames(2,6,14,10,True)
plc4 = playerLasers[4].getCollider()
plc4.setColliderSize(0,0,6,14)




pobj = eng.findObjectByName("player")

back = eng.findObjectByName("background")


_enemsClass = []
_lasersClass = []
_enemLasersClass = []
for i in range(5):
	_enemsClass.append(Enemy.Enemy(enemies[i],eng))
	_lasersClass.append(Projectile.Projectile(playerLasers[i],eng,-5))
	_enemLasersClass.append(EnemyProjectile.EnemyProjectile(enemyLasers[i],eng,4))


enemControl = EnemyController.EnemyController(_enemsClass,_enemLasersClass)
hero = Player.Player(pobj,eng,_lasersClass)
gameRules = GameLogic.GameLogic()
scoreUI = UI.UI(scoreText,eng,0, "Score: ")
livesUI = UI.UI(livesText,eng,3, "Lives: ")
statusUI = UI.UI(statusText,eng," ", "Game Over")

quit = False
pause = False
waitForKeyUp = True
while(not quit):
	if not pause:
		eng.startFrame()
		eng.clearScreen()

		inputReceived = inSys.checkForInput();

		if(inputReceived == "quit"):
			quit = True
			break;
		enemControl.update()

		hero.update(inputReceived ,enemControl, gameRules)
		scoreUI.update("Score: ",gameRules.get_score())
		livesUI.update("Lives: ", gameRules.get_lives())

		if(gameRules.is_game_over()):
			statusUI.updateText("Game Over. Press Space to Play Again!")
			statusUI.render()
			pause = True


		back.render(ge.ImgFlip.NONE)
		enemControl.render()
		#bgt.render(ge.ImgFlip.NONE)
		hero.render()
		scoreUI.render()
		livesUI.render()
		if pause:
			statusUI.render()
		#lText.render(600,0,0,ge.ImgFlip.NONE)
		#sText.render(0,0,0,ge.ImgFlip.NONE)

		eng.renderScreen()
		eng.endFrame()

	else:
		inputReceived = inSys.checkForInput();
		if(inputReceived == "quit"):
			quit = True
			break;
		if inputReceived == "fire":
			gameRules.reset()
			enemControl.reset()
			scoreUI.update("Score: ",gameRules.get_score())
			livesUI.update("Lives: ", gameRules.get_lives())
			pause = False

