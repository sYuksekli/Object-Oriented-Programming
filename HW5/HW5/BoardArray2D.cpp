#include "BoardArray2D.h"

namespace GtuGame
{
	// No parameter constructor
	BoardArray2D::BoardArray2D():AbstractBoard(),row(3),col(3)
	{
		arr = new int*[3];
		for (int i = 0; i < 3; ++i)
			arr[i] = new int[3];
	}

	// Constructor to initialize data members according to function parameters.
	BoardArray2D::BoardArray2D(int rowValue, int colValue, int** array):AbstractBoard(),row(rowValue),col(colValue)
	{
		arr = new int*[rowValue];
		for (int i = 0; i < rowValue; ++i)
			arr[i] = new int[colValue];

		for (int i = 0; i < rowValue; ++i)
			for (int j = 0; j < colValue; ++j)
				arr[i][j]  = array[i][j];
	}

	/*  BIG THREE */
	// Copy Constructor 
	BoardArray2D::BoardArray2D(const BoardArray2D& otherBoard)
	{	
		LastMove = otherBoard.LastMove;
		NumberOfMoves = otherBoard.NumberOfMoves;
		game_format = otherBoard.game_format;
		row = otherBoard.row;
		col = otherBoard.col;

		arr = new int*[row];
		for (int i = 0; i < row; ++i)
			arr[i] = new int[col];

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				arr[i][j] = otherBoard.arr[i][j];
	}

	// Assignment operator
	const BoardArray2D& BoardArray2D::operator=(const BoardArray2D& rightSide)
	{
		if (this == &rightSide)
			return *this;
	
		else{

			for (int i = 0; i < row; ++i)
				delete [] arr[i];
			delete [] arr;

			this->LastMove = rightSide.LastMove;
			this->NumberOfMoves = rightSide.NumberOfMoves;
			this->game_format = rightSide.game_format;
			this->row = rightSide.row;
			this->col = rightSide.col;

			arr = new int*[row];
			for (int i = 0; i < row; ++i)
				arr[i] = new int[col];

			for (int i = 0; i < row; ++i)
				for (int j = 0; j < col; ++j)
					arr[i][j] = rightSide.arr[i][j];

			return *this;
		}
	}

	// Desctructor
	BoardArray2D::~BoardArray2D()
	{
		for (int i = 0; i < row; ++i)
			delete [] arr[i];
		delete [] arr;
	}

	// Prints the current configuration on the screen.
	void BoardArray2D::print() const
	{
		if (game_format == 1)
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if(arr[i][j]==-1) 		// if it is blank tile, don't print to the screen.
						cout << "  ";
					else
						cout << arr[i][j] <<" ";
				}

				cout << endl;
			}
		}

		else
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if(arr[i][j] == -1) 
						cout << "bb" <<" ";	 // if it is blank tile, print as 'bb' to the screen.

					else if (arr[i][j] == 0)
						cout << "00" <<" ";	 // It represents walls.
			
					else{

						if (arr[i][j] < 10)
							cout <<"0"<<arr[i][j] <<" ";  // For one-digit numbers.
						else
							cout << arr[i][j] <<" ";
					}
				}

				cout << endl;
			}
		}
	}

	// Reads game board from file.
	void BoardArray2D::readFromFile(std::string fileName)
	{
		int rowValue = 0;
		int colValue = 0;

		string line;
		string line2;
		string word;
		string wordd;

		const auto blankStr = "bb";

		ifstream file(fileName);
		if (file.is_open())
		{

			while (getline (file,line)){        // To find number of rows
        		++ rowValue;

       	 		stringstream strStream(line);
        		while ( strStream >> word )     // To find number of columns
					++ colValue;	
	    	}

    		colValue = colValue / rowValue;

    		// number of the current row and column can be different from size of the shape file.
   		 	// So it allocates memory and initializes data members.
    		setSize(rowValue,colValue);

			int i = 0; // row
			int j = 0; // col

			ifstream file2(fileName);
			while (getline(file2,line2)){

				cout << line2 << endl;			// It prints shape file to the screen.

				stringstream strStream2(line2);
				while( strStream2 >> wordd){

					if (wordd.compare(blankStr) == 0)
						arr[i][j] = -1;
					
					else
						arr[i][j] = stoi(wordd);
				
					++j;
				}

				j=0;
				++i;	
			}

			file.close();
		}

		else
			cout << "Unable to open file" << endl;

		LastMove = 'S';
		NumberOfMoves = 0;
	}

	// Writes the current configuration to a file.
	void BoardArray2D::writeToFile(std::string fileName) const
	{
		ofstream file;
		file.open(fileName);
	
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if(arr[i][j]==-1) 			// bb is blank tile.
					file << "bb" <<" ";

				else if (arr[i][j] == 0)	// 00 is wall.
					file << "00" <<" ";
		
				else{

					if (arr[i][j] < 10)
						file << "0" <<arr[i][j] <<" ";	// If number is one-digit
					else
						file << arr[i][j] <<" ";
				}
			}

			file << endl;
		}

		file.close();
	}

	// Resets the current configuration to solution.
	void BoardArray2D::reset()
	{
		int curVal = 1;
		if (game_format == 1)
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					arr[i][j] = curVal;
					++curVal;
			
					if (i == row-1 && j== col-1)
						arr[i][j] = -1;				
				}
			}
		}

		else
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{

					if (arr[i][j] != 0)
					{
						arr[i][j] = curVal;
						++curVal;
					}

					if (i == row-1 && j== col-1)
						arr[i][j] = -1;	
				}
			}
		}
	}

	// Sets the size of the board according to given values.
	void BoardArray2D::setSize(int rowValue, int colValue)
	{
		if (rowValue > 2 && rowValue < 10 && colValue > 2 && colValue < 10) 
		{	

			for (int i = 0; i < row; ++i)
				delete [] arr[i];
			delete [] arr;

			row = rowValue;
 			col = colValue;

 			arr = new int*[row];
 			for (int i = 0; i < row; ++i)
 				arr[i] = new int[col];
		}

		else{

			cout << "Invalid index values" << endl;
			exit(1);
		}
	}

	// Makes a move according to the char parameter(Right, Left, Up, Down)
	void BoardArray2D::move(char move)
	{
		if (game_format == 2)
		{
			if (move == 'U')
			{
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[i][j]== -1 && (i-1)>=0 && arr[i-1][j] != 0)
						{
							arr[i][j] = arr[i-1][j];
							arr[i-1][j] = -1;
						}
					}
				}
			}

			if (move == 'D')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[i][j]== -1 && (i+1)<row && arr[i+1][j] != 0)
						{
							arr[i][j] = arr[i+1][j];
							arr[i+1][j] = -1;
							return;	
							// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
						}
					}	
				}
			}

			if (move == 'L')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[i][j]== -1 && (j-1)>=0 && arr[i][j-1] != 0)
						{
							arr[i][j] = arr[i][j-1];
							arr[i][j-1] = -1;
						}
					}
				}
			}

			if (move == 'R')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[i][j]== -1 && (j+1)<col && arr[i][j+1] != 0)
						{
							arr[i][j] = arr[i][j+1];
							arr[i][j+1] = -1;
							return; 
							// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
						}
					}
				}
			}
		} // end of the file format 2.


		else
		{
			if (move == 'D'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[i][j]== -1 && (i+1)<row )
						{
							arr[i][j] = arr[i+1][j];
							arr[i+1][j] = -1;
							return;	
							// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
						}
					}
				}	
			}

			if (move == 'U'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[i][j]== -1 && (i-1)>=0 )
						{
							arr[i][j] = arr[i-1][j];
							arr[i-1][j] = -1;
						}
					}
				}
			}

			if (move == 'L'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[i][j]== -1 && (j-1)>=0 )
						{
							arr[i][j] = arr[i][j-1];
							arr[i][j-1] = -1;
						}
					}
				}
			}

			if (move == 'R'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[i][j]== -1 && (j+1)<col )
						{
							arr[i][j] = arr[i][j+1];
							arr[i][j+1] = -1;
							return; 
							// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
						}
					}
				}
			}
		} // end of the file format 1	
	}

	// Checks whether the game is solved.
	bool BoardArray2D::isSolved() const
	{
		int curVal = 1;
		int rowValue = row;
		int colValue = col;

		if (game_format == 1)				// For HW1 format
		{
			for (int i = 0; i < rowValue; ++i){
		
				if(i == rowValue-1) 		// -1 represents blank tile. I reduce size, because last tile has to be blank. 
					colValue--;

				for (int j = 0; j < colValue; ++j)
					if(arr[i][j]!=curVal++)
						return false;	
			}
			return true;
		}

		else
		{
			for (int i = 0; i < rowValue; ++i)
			{
				if (i == rowValue-1) 		 // -1 represents blank tile.It has to be at the lower right corner.
					--colValue;
			
				for (int j = 0; j < colValue; ++j)
				{
					if (arr[i][j] != 0) { 	 // 0 is the impossible tile.

						if (arr[i][j] != curVal++)
							return false;
					}
				}
			} 	

			return true;
		}
	}

	// Returns the cell content which belongs to parameter values.
	int BoardArray2D::operator()(int xIndex, int yIndex) const
	{
		if (xIndex >= 0 && yIndex >= 0 && xIndex < row && yIndex < col)
		{
			return arr[xIndex][yIndex];
		}

		else{

			cout << "Invalid index values" << endl;
			exit(1);
		}
	}

	// Compares two boards to each other, last move, number of moves and other data members are ignored.
	bool BoardArray2D::operator==(const AbstractBoard& otherBoard) const
	{	
		for (int i = 0; i < otherBoard.getRow(); ++i)
		{
			for (int j = 0; j < otherBoard.getCol(); ++j)
			{
				if (this->operator()(i,j) != otherBoard(i,j))
				{
					return false;
				}
			}
		}
		
		return true;
	}

	// It finds the location of blank tile.
	void BoardArray2D::findEmptyNode(int& cur_i, int& cur_j) const{

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if(arr[i][j] == -1){  	// -1 represents blank tile.
					cur_i = i;
					cur_j = j;
					return;
				}
			}
		}
	}

	// Returns value of row of board
	int BoardArray2D::getRow() const
	{
		return row;
	}

	// Returns value of column of the board
	int BoardArray2D::getCol() const
	{
		return col;
	}

}