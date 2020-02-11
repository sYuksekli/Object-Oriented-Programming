#include "BoardArray1D.h"

namespace GtuGame
{
	// No parameter constructor
	BoardArray1D::BoardArray1D():AbstractBoard(),row(3),col(3)
	{
		arr = new int[9];
	}

	// Constructor to initialize data members according to function parameters.
	BoardArray1D::BoardArray1D(int rowValue, int colValue, int* array):AbstractBoard(),row(rowValue),col(colValue)
	{
		arr = new int[rowValue*colValue];
		for (int i = 0; i < rowValue*colValue; ++i)
			arr[i] = array[i];
	}

	/*  BIG THREE*/
	// Copy Constructor 
	BoardArray1D::BoardArray1D(const BoardArray1D& otherBoard)
	{	
		LastMove = otherBoard.LastMove;
		NumberOfMoves = otherBoard.NumberOfMoves;
		game_format = otherBoard.game_format;
		row = otherBoard.row;
		col = otherBoard.col;

		arr = new int[row*col];

		for (int i = 0; i < row*col; ++i)
			arr[i] = otherBoard.arr[i];
	}

	// Assignment operator
	const BoardArray1D& BoardArray1D::operator=(const BoardArray1D& rightSide)
	{
		if (this == &rightSide)
			return *this;
	
		else{

			delete [] arr;

			this->LastMove = rightSide.LastMove;
			this->NumberOfMoves = rightSide.NumberOfMoves;
			this->game_format = rightSide.game_format;
			this->row = rightSide.row;
			this->col = rightSide.col;

			arr = new int[row*col];

			for (int i = 0; i < row*col; ++i)
				arr[i] = rightSide.arr[i];

			return *this;
		}
	}

	// Desctructor
	BoardArray1D::~BoardArray1D()
	{
		delete [] arr;
	}

	// Prints the current configuration on the screen.
	void BoardArray1D::print() const
	{	
		int k=0;
		if (game_format == 1)
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if(arr[k]==-1) 		// if it is blank tile, don't print to the screen.
						cout << "  ";
					else
						cout << arr[k] <<" ";
					++k;
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
					if(arr[k] == -1) 
						cout << "bb" <<" ";	 // if it is blank tile, print as 'bb' to the screen.

					else if (arr[k] == 0)
						cout << "00" <<" ";	 // It represents walls.
			
					else{

						if (arr[k] < 10)
							cout <<"0"<<arr[k] <<" ";  // For one-digit numbers.
						else
							cout << arr[k] <<" ";
					}

					++k;
				}

				cout << endl;
			}
		}
	}

	// Reads game board from file.
	void BoardArray1D::readFromFile(string fileName)
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

			int i = 0;

			ifstream file2(fileName);
			while (getline(file2,line2)){

				cout << line2 << endl;			// It prints shape file to the screen.

				stringstream strStream2(line2);
				while( strStream2 >> wordd){

					if (wordd.compare(blankStr) == 0)
						arr[i] = -1;
					
					else
						arr[i] = stoi(wordd);
				
					++i;
				}	
			}

			file.close();
		}

		else
			cout << "Unable to open file" << endl;

		LastMove = 'S';
		NumberOfMoves = 0;
	}

	// Writes the current configuration to a file.
	void BoardArray1D::writeToFile(string fileName) const
	{
		ofstream file;
		file.open(fileName);
		
		int k = 0;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if(arr[k]==-1) 			// bb is blank tile.
					file << "bb" <<" ";

				else if (arr[k] == 0)	// 00 is wall.
					file << "00" <<" ";
		
				else{

					if (arr[k] < 10)
						file << "0" <<arr[k] <<" ";	// If number is one-digit
					else
						file << arr[k] <<" ";
				}

				++k;
			}

			file << endl;
		}

		file.close();
	}

	// Resets the current configuration to solution.
	void BoardArray1D::reset()
	{
		int curVal = 1;
		int k = 0;
		if (game_format == 1)
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					arr[k] = curVal;
					++curVal;
			
					if (i == row-1 && j== col-1)
						arr[k] = -1;

					++k;				
				}
			}
		}

		else
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{

					if (arr[k] != 0)
					{
						arr[k] = curVal;
						++curVal;
					}

					if (i == row-1 && j== col-1)
						arr[k] = -1;	
				
					++k;
				}
			}
		}
	}

	// Sets the size of the board according to given values.
	void BoardArray1D::setSize(int rowValue, int colValue)
	{
		if (rowValue > 2 && rowValue < 10 && colValue > 2 && colValue < 10) 
		{	
			delete [] arr;

			row = rowValue;
 			col = colValue;

 			arr = new int[row*col];
		}

		else{

			cout << "Invalid index values" << endl;
			exit(1);
		}
	}

	// Makes a move according to the char parameter(Right, Left, Up, Down)
	void BoardArray1D::move(char move)
	{	
		int k = 0;
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
						if (arr[k]== -1 && (i-1)>=0 && arr[k-col] != 0)
						{
							arr[k] = arr[k-col];
							arr[k-col] = -1;
						}
						
						++k;
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
						if (arr[k]== -1 && (i+1)<row && arr[k+col] != 0)
						{
							arr[k] = arr[k+col];
							arr[k+col] = -1;
							return;	
							// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
						}

						++k;
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
						if (arr[k]== -1 && (j-1)>=0 && arr[k-1] != 0)
						{
							arr[k] = arr[k-1];
							arr[k-1] = -1;
						}

						++k;
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
						if (arr[k]== -1 && (j+1)<col && arr[k+1] != 0)
						{
							arr[k] = arr[k+1];
							arr[k+1] = -1;
							return; 
							// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
						}

						++k;
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
						if (arr[k]== -1 && (i+1)<row )
						{
							arr[k] = arr[k+col];
							arr[k+col] = -1;
							return;	
							// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
						}

						++k;
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
						if (arr[k]== -1 && (i-1)>=0 )
						{
							arr[k] = arr[k-col];
							arr[k-col] = -1;
						}

						++k;
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
						if (arr[k]== -1 && (j-1)>=0 )
						{
							arr[k] = arr[k-1];
							arr[k-1] = -1;
						}

						++k;
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
						if (arr[k]== -1 && (j+1)<col )
						{
							arr[k] = arr[k+1];
							arr[k+1] = -1;
							return; 
							// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
						}

						++k;
					}
				}
			}
		} // end of the file format 1	
	}

	// Checks whether the game is solved.
	bool BoardArray1D::isSolved() const
	{
		int curVal = 1;
		int rowValue = row;
		int colValue = col;
		int k = 0;

		if (game_format == 1)				// For HW1 format
		{
			for (int i = 0; i < rowValue; ++i){
		
				if(i == rowValue-1) 		// -1 represents blank tile. I reduce size, because last tile has to be blank. 
					colValue--;

				for (int j = 0; j < colValue; ++j)
					if(arr[k]!=curVal++)
						return false;	
					++k;
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
					if (arr[k] != 0) { 	 // 0 is the impossible tile.

						if (arr[k] != curVal++)
							return false;
						++k;
					}
				}
			} 	

			return true;
		}
	}

	// Returns the cell content which belongs to parameter values.
	int BoardArray1D::operator()(int xIndex, int yIndex) const
	{
		if (xIndex >= 0 && yIndex >= 0 && xIndex < row && yIndex < col)
		{	
			int k = 0;
			for (int i = 0; i < row; ++i){
				for (int j = 0; j < col; ++j){
					if (i== xIndex && j==yIndex)
						return arr[k];
					else
						++k;
				}
			}
		}

		else{

			cout << "Invalid index values" << endl;
			exit(1);
		}
	}

	// Compares two boards to each other, last move, number of moves and other data members are ignored.
	bool BoardArray1D::operator==(const AbstractBoard& otherBoard) const
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
	void BoardArray1D::findEmptyNode(int& cur_i, int& cur_j) const{

		for (int i = 0; i < row*col; ++i)
		{
			if (arr[i] == -1)
			{
				cur_i = i;
				cur_i = i / col; // This type of board is represented with one-dimensional array
				cur_j = i % col; // But, it is actually two-dimensional. So, I find the x, y coordinate
				return;			 // of board like this.
			}
		}
			
	}

	// Returns value of row of board
	int BoardArray1D::getRow() const
	{
		return row;
	}

	// Returns value of column of board
	int BoardArray1D::getCol() const
	{
		return col;
	}

}