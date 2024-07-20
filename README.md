# Click Blitz

## Demo Video

Watch the demo video [here](https://www.youtube.com/watch?v=SkuCNROAEk4).

## Setup on Linux

### Compilation

First, create a `build` directory and compile the source files:

```bash
mkdir build
g++ -c src/main.cpp -o build/main.o -Iinclude
g++ -c src/Enemy.cpp -o build/Enemy.o -Iinclude
g++ -c src/Game.cpp -o build/Game.o -Iinclude
g++ -c src/utils.cpp -o build/utils.o -Iinclude
```

### Linking

Create a bin directory and link the object files to produce the executable:

```bash
mkdir bin
g++ -o bin/main build/main.o build/Enemy.o build/Game.o build/utils.o -Llib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```

### Run

Set the LD_LIBRARY_PATH and execute the program:

```bash
LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH ./bin/main
```