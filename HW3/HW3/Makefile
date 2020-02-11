all:hw3
hw3: main.o NPuzzle.o
	g++ -std=c++11 main.o NPuzzle.o -o hw3
main.o: main.cpp 
	g++ -std=c++11 -c main.cpp 
NPuzzle.o: NPuzzle.cpp
	g++ -std=c++11 -c NPuzzle.cpp 
clean: rm -rf *o hw3