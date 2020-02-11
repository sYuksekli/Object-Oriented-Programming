all:hw2
hw2: main.o puzzle.o
	g++ -std=c++11 main.o puzzle.o -o hw2
main.o: main.cpp 
	g++ -std=c++11 -c main.cpp 
puzzle.o: puzzle.cpp
	g++ -std=c++11 -c puzzle.cpp 
clean: rm -rf *o hw2