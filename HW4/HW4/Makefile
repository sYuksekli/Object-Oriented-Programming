all:hw4
hw4: main.o NPuzzle.o
	g++ -std=c++11 main.o NPuzzle.o -o hw4
main.o: main.cpp 
	g++ -std=c++11 -c main.cpp 
NPuzzle.o: NPuzzle.cpp
	g++ -std=c++11 -c NPuzzle.cpp 
clean: rm -rf *o hw4