#ifndef ABSTRACTBOARD_H_
#define ABSTRACTBOARD_H_

#include <string>
using namespace std;

namespace GtuGame{

	class AbstractBoard
	{
		
	public:
		AbstractBoard();
	    virtual ~AbstractBoard() = default;
		virtual void print() const = 0;
		virtual void readFromFile(std::string fileName) = 0;
		virtual void writeToFile(std::string fileName) const = 0;
		virtual void reset() = 0;
		virtual void setSize(int rowValue, int colValue) = 0;
		virtual void move(char move) = 0;
		virtual bool isSolved() const = 0;
		virtual int operator()(int xIndex, int yIndex) const = 0;
		virtual bool operator==(const AbstractBoard& otherBoard) const = 0;
		virtual void findEmptyNode(int& cur_i, int& cur_j) const = 0;
		virtual int getCol() const = 0;
		virtual int getRow() const = 0;
		void set_game_format(int format);
		static int NumberOfBoards();
		char lastMove() const;
		int numberOfMoves() const;

	protected:
		static int numberOfBoards;
		char LastMove;
		int NumberOfMoves;
		int game_format;
	};
}



#endif