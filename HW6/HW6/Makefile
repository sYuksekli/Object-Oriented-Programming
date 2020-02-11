all:hw6
hw6: main.o GTUContainer.o GTUVector.o GTUSet.o GTUIterator.o GTUIteratorConst.o 
	g++ GTUContainer.o main.o GTUVector.o GTUSet.o GTUIterator.o GTUIteratorConst.o -o hw6
main.o:main.cpp 
	g++ -c main.cpp -std=c++11 
GTUContainer.o:GTUContainer.cpp
	g++ -c GTUContainer.cpp  -std=c++11 
GTUVector.o:GTUVector.cpp
	g++ -c GTUVector.cpp -std=c++11 
GTUSet.o:GTUSet.cpp
	g++ -c GTUSet.cpp -std=c++11 
GTUIterator.o:GTUIterator.cpp
	g++ -c GTUIterator.cpp -std=c++11
GTUIteratorConst.o:GTUIteratorConst.cpp
	g++ -c GTUIteratorConst.cpp -std=c++11  
clean: 
	rm -rf *o hw6