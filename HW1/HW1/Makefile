all:hw1
hw1: main.o source.o
	g++ -std=c++11 main.o source.o -o hw1
main.o: main.cpp 
	g++ -std=c++11 -c main.cpp 
source.o: source.cpp
	g++ -std=c++11 -c source.cpp 
clean: rm -rf *o hw1