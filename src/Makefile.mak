
derle:

	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./lib/Maze.o -c ./src/Maze.cpp
	g++ -I ./include/ -o ./bin/Maze ./lib/Stack.o ./lib/Maze.o ./src/main.cpp
    

calistir:
	./bin/Labirent.exe