#ifndef BOARDARRAY1D_H_
#define BOARDARRAY1D_H_

#include "AbstractBoard.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace GtuGame{

	class BoardArray1D : public AbstractBoard
	{

	public:
		BoardArray1D();
		BoardArray1D(int rowValue, int colValue, int* array);

		// Big three
		BoardArray1D(const BoardArray1D& otherBoard);
		const BoardArray1D& operator=(const BoardArray1D& rightSide);
		~BoardArray1D();

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
		int *arr;
		int row;
		int col;
		
	};
	
}

#endif