Website:
https://boseeinstein.github.io/FinalProjectPage/

Running the game:

Inside the Game directory run:

python3 SpaceGame.py

To access the GameMaker GUI, first ensure Tkinter and Pillow are installed with:

sudo apt-get install python3-tk
pip3 install pillow

Be sure to build the library as well (see below)
Then, from the Project/gui directory, run:

./Engine_GUI

Build Game Library:
To build our game engine python module from scratch go to the Project Directory and enter:

sh exSDL.sh

This works for MINGW on Windows
For linux, run:

python3 exSDL.py

The library will be built as ge.pyd and be placed in the Game Directory.
Place ge.pyd as well as copy all the .dll files and Acme-Regular.tff in Game directory to whatever directory you are working in and in your python script use:

import ge

From there you will have full access to the API through the ge module. It is recommended to first create a GameEngine object with a call:

engine = ge.GameEngine(width,height)

With your desired screen width and height. Then create and retrieve objects through the engine object. Happy Gaming!
