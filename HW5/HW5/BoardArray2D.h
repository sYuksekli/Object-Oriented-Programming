#ifndef BOARDARRAY2D_H_
#define BOARDARRAY2D_H_

#include "AbstractBoard.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace GtuGame{

	class BoardArray2D : public AbstractBoard
	{

	public:
		BoardArray2D();
		BoardArray2D(int rowValue, int colValue, int** array);

		// Big three
		BoardArray2D(const BoardArray2D& otherBoard);
		const BoardArray2D& operator=(const BoardArray2D& rightSide);
		~BoardArray2D();

		void print() const override;
		void readFromFile(std::string fileName) override;
		void writeToFile(std::string fileName) const override;
		void reset() override;
		void setSize(int rowValue, int colValue) override;
		void move(char move) override;
		bool isSolved() const override;
		int operator()(int xIndex, int yIndex) const override;
		bool operator==(const AbstractBoard& otherBoard) const override;
		void findEmptyNode(int& cur_i, int& cur_j) const override;
		int getCol() const override;
		int getRow() const override;

	private:
		int **arr;
		int row;
		int col;
		
	};
	
}

#endif