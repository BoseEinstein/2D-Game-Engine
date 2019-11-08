# Run with sh mingw64build.sh


COMPILE="g++ -D MINGW -std=c++14 -shared -fPIC -static-libgcc -static-libstdc++ -I./include/SDL2/ -I./include/ -I./pybind11/include/ `python3.6 -m pybind11 --includes` ./src/*.cpp -o ./Game/ge.pyd `python3.6-config --ldflags` -L./lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -mwindows -L libwinpthread-1.dll"


echo $COMPILE
echo "-------------------------------------------"
eval $COMPILE
