#ifndef NPUZZLE_H_ 
#define NPUZZLE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

class NPuzzle
{

public:

	NPuzzle();
	void setNumberOfMoves(int move);
	void setFormatChoice(int format);
	void print() const;
	void printReport() const;
	const int readFromFile(string fileName);
	void writeToFile(string fileName) const;
	void shuffle(int numberOfRandomMoves);
	void reset();
	void setsize(int rowValue, int colValue);
	void moveRandom();
	void fillRandom();
	const char moveIntelligent();
	void move(char move);
	const int solvePuzzle();
	const bool isSolved() const;
	const bool checkSolvable() const;

private:

	class Board
	{

	public:

		Board();
		Board(int rowValue, int colValue);
		int getRow() const;
		int getCol() const;
		int ** getBoard() const;
		void set_format_choice(int format);
		void print() const;
		const int readFromFile(string fileName);
		void writeToFile(string fileName) const;
		void reset();
		void setsize(int rowValue, int colValue);
		void move(char move);
		const bool isSolved() const;
		void findEmptyNode(int& cur_i, int& cur_j) const;
		const bool checkValidty(int i,int j) const;
		void fillRandom();
		const int getInversionNumber() const;
		const int findBlankPosition() const;

	private:

		int ** arr;
		int row;
		int col;
		int format_choice;
	};

	void move(char move, int ** arr, int rowValue, int colValue);
	const int findCloseness(int ** arr, int rowValue, int colValue) const;
	const bool getStuck(char * arrChoice, char intelligentMoveChoice, int currentSize) const;

	int formatChoice;
	int numberOfMoves;
	NPuzzle::Board board1;
	NPuzzle::Board board2;
	
};


#endif