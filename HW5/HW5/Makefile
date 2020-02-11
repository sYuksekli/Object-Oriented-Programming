all:hw5
hw5: main.o AbstractBoard.o BoardVector.o BoardArray2D.o BoardArray1D.o
	g++ AbstractBoard.o main.o BoardVector.o BoardArray2D.o BoardArray1D.o -o hw5
main.o:main.cpp 
	g++ -c main.cpp -std=c++11 
AbstractBoard.o:AbstractBoard.cpp
	g++ -c AbstractBoard.cpp  -std=c++11 
BoardVector.o:BoardVector.cpp
	g++ -c BoardVector.cpp -std=c++11 
BoardArray2D.o:BoardArray2D.cpp
	g++ -c BoardArray2D.cpp -std=c++11 
BoardArray1D.o:BoardArray1D.cpp
	g++ -c BoardArray1D.cpp -std=c++11 
clean: 
	rm -rf *o hw5