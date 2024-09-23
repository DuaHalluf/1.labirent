hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./lib/maze.o -c ./src/maze.cpp
	g++ -I ./include/ -o ./bin/maze ./lib/main.o ./lib/maze.o

calistir:
	./bin/maze