#ifndef BOARDVECTOR_H_
#define BOARDVECTOR_H_

#include "AbstractBoard.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

namespace GtuGame{

	class BoardVector : public AbstractBoard
	{

	public:
		/* Default big three is ok for vector */
		BoardVector();
		BoardVector(vector<vector<int>> & vect);
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
		vector<vector<int>> boardVector;
	};
}


#endif