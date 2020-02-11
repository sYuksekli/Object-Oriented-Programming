#ifndef NPUZZLE_H_ 
#define NPUZZLE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class NPuzzle
{

public:

	NPuzzle();
	void setGameFormat(int format);
	void print() const;
	void printReport() const;
	int readFromFile(string fileName);
	void writeToFile(string fileName) const;
	void shuffle(int numberOfRandomMoves);
	void reset();
	void setsize(int rowValue, int colValue);
	void moveRandom();
	void fillRandom();
	void move(char move);
	void solvePuzzle(int format);
	friend ostream& operator<<(ostream& outputStream, const NPuzzle& puzzle);
	friend istream& operator>>(istream& inputStream, NPuzzle& puzzle);
	bool isSolved() const;
	bool checkSolvable() const;

private:

	class Board
	{

	public:

		Board();
		Board(vector<vector<int>> & vect, int numberOfMoves, int LastMove);
		static int NumberOfBoards();
		char lastMove() const;
		int numberOfMoves() const;
		int getRowOfBoard() const;
		int getColOfBoard() const;
		int getGameFormat() const;
		const vector<vector<int>> & getBoard() const;
		void setBoard(int xIndex, int yIndex, int value);
		void setLastMove(char move);
		void set_game_format(int format);
		void setNumberOfMoves(int numOfMoves);
		void print() const;
		int readFromFile(string fileName);
		void writeToFile(string fileName) const;
		void reset();
		void setSize(int rowValue, int colValue);
		void move(char move);
		bool isSolved() const;
		void findEmptyNode(int& cur_i, int& cur_j) const;
		bool checkValidty(int i,int j) const;
		void fillRandom();
		int getInversionNumber() const;
		int findBlankPosition() const;
		int operator()(int xIndex, int yIndex) const;
		bool operator==(const NPuzzle::Board& otherBoard) const;
		
	private:

		static int numberOfBoards;
		vector<vector<int>> boardVector;
		char LastMove;
		int NumberOfMoves;
		int game_format;
	};

	vector<Board> boards;
	
};


#endif