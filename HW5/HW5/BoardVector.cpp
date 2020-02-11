#include "BoardVector.h"

namespace GtuGame{

	// No parameter constructor.
	BoardVector::BoardVector():AbstractBoard() {/*	*/}

	// Constructor to initialize data members according to function parameters.
	BoardVector::BoardVector(vector<vector<int>> & vect):AbstractBoard(),boardVector(vect) {/*	*/}

	// Prints the current configuration on the screen.
	void BoardVector::print() const
	{

		if (game_format == 1)
		{
			for (int i = 0; i < boardVector.size(); ++i)
			{
				for (int j = 0; j < boardVector[i].size(); ++j)
				{
					if(boardVector[i][j]==-1) 		// if it is blank tile, don't print to the screen.
						cout << "  ";
					else
						cout << boardVector[i][j] <<" ";
				}

				cout << endl;
			}
		}

		else
		{
			for (int i = 0; i < boardVector.size(); ++i)
			{
				for (int j = 0; j < boardVector[i].size(); ++j)
				{
					if(boardVector[i][j] == -1) 
						cout << "bb" <<" ";	 // if it is blank tile, print as 'bb' to the screen.

					else if (boardVector[i][j] == 0)
						cout << "00" <<" ";	 // It represents walls.
			
					else{

						if (boardVector[i][j] < 10)
							cout <<"0"<<boardVector[i][j] <<" ";  // For one-digit numbers.
						else
							cout << boardVector[i][j] <<" ";
					}
				}

				cout << endl;
			}
		}
	}

	// Reads game board from file.
	void BoardVector::readFromFile(std::string fileName)
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
    		// So it sets size of the board.
   		 	setSize(rowValue,colValue);

			int i = 0; // row
			int j = 0; // col

			ifstream file2(fileName);
			while (getline(file2,line2)){

				cout << line2 << endl;			// It prints shape file to the screen.

				stringstream strStream2(line2);
				while( strStream2 >> wordd){

					if (wordd.compare(blankStr) == 0)
						boardVector[i][j] = -1;
					
					else
						boardVector[i][j] = stoi(wordd);
				
					++j;
				}

				j=0;
				++i;	
			}

			file.close();
		}

		else{
			cout << "Unable to open file" << endl;
			exit(1);
		}

		LastMove = 'S';
		NumberOfMoves = 0;

	}

	// Writes the current configuration to a file.
	void BoardVector::writeToFile(std::string fileName) const
	{
		ofstream file;
		file.open(fileName);
	
		for (int i = 0; i < boardVector.size(); ++i)
		{
			for (int j = 0; j < boardVector[i].size(); ++j)
			{
				if(boardVector[i][j]==-1) 			// bb is blank tile.
					file << "bb" <<" ";

				else if (boardVector[i][j] == 0)	// 00 is wall.
					file << "00" <<" ";
		
				else{

					if (boardVector[i][j] < 10)
						file << "0" <<boardVector[i][j] <<" ";	// If number is one-digit
					else
						file << boardVector[i][j] <<" ";
				}
			}

			file << endl;
		}

		file.close();
	}

	// Resets the current configuration to solution.
	void BoardVector::reset()
	{
		int curVal = 1;
		if (game_format == 1)
		{
			for (int i = 0; i < boardVector.size(); ++i)
			{
				for (int j = 0; j < boardVector[i].size(); ++j)
				{
					boardVector[i][j] = curVal;
					++curVal;
			
					if (i == boardVector.size()-1 && j== boardVector[i].size()-1)
						boardVector[i][j] = -1;		
				}
			}
		}

		else
		{
			for (int i = 0; i < boardVector.size(); ++i)
			{	
				for (int j = 0; j < boardVector[i].size(); ++j)
				{

					if (boardVector[i][j] != 0)
					{
						boardVector[i][j] = curVal;
						++curVal;
					}

					if (i == boardVector.size()-1 && j== boardVector[i].size()-1)
						boardVector[i][j] = -1;	
				}
			}
		}
	}

	// Sets the size of the board according to given values.
	void BoardVector::setSize(int rowValue, int colValue)
	{	
		if (rowValue > 2 && rowValue < 10 && colValue > 2 && colValue < 10) 
		{	
			for (int i = 0; i < boardVector.size(); ++i)
				boardVector[i].erase(boardVector[i].begin(),boardVector[i].end());

			boardVector.erase(boardVector.begin(),boardVector.end());
			boardVector.resize(rowValue);
			
 			for (int i = 0; i <boardVector.size(); ++i)
 				boardVector[i].resize(colValue);
		}	

		else{

			cout << "Invalid index values" << endl;
			exit(1);
		}
	}

	// Makes a move according to the char parameter(Right, Left, Up, Down)
	void BoardVector::move(char move)
	{
		if (game_format == 2)
		{

			if (move == 'U')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < boardVector.size(); ++i)
				{
					for (int j = 0; j < boardVector[i].size(); ++j)
					{
						if (boardVector[i][j]== -1 && (i-1)>=0 && boardVector[i-1][j] != 0)
						{
							boardVector[i][j] = boardVector[i-1][j];
							boardVector[i-1][j] = -1;
						}
					}
				}
			}

			if (move == 'D')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < boardVector.size(); ++i)
				{
					for (int j = 0; j < boardVector[i].size(); ++j)
					{
						if (boardVector[i][j]== -1 && (i+1)<boardVector.size() && boardVector[i+1][j] != 0)
						{
							boardVector[i][j] = boardVector[i+1][j];
							boardVector[i+1][j] = -1;
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
				for (int i = 0; i < boardVector.size(); ++i)
				{
					for (int j = 0; j < boardVector[i].size(); ++j)
					{	
						if (boardVector[i][j]== -1 && (j-1)>=0 && boardVector[i][j-1] != 0)
						{
							boardVector[i][j] = boardVector[i][j-1];
							boardVector[i][j-1] = -1;
						}
					}
				}
			}

			if (move == 'R')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < boardVector.size(); ++i)
				{
					for (int j = 0; j < boardVector[i].size(); ++j)
					{
						if (boardVector[i][j]== -1 && (j+1)< boardVector[i].size() && boardVector[i][j+1] != 0)
						{
							boardVector[i][j] = boardVector[i][j+1];
							boardVector[i][j+1] = -1;
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
				for (int i = 0; i < boardVector.size(); ++i)
				{
					for (int j = 0; j < boardVector[i].size(); ++j)
					{
						if (boardVector[i][j]== -1 && (i+1)<boardVector.size())
						{
							boardVector[i][j] = boardVector[i+1][j];
							boardVector[i+1][j] = -1;
							return;	
							// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
						}
					}
				}	
			}

			if (move == 'U'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < boardVector.size(); ++i)
				{
					for (int j = 0; j < boardVector[i].size(); ++j)
					{
						if (boardVector[i][j]== -1 && (i-1)>=0 )
						{
							boardVector[i][j] = boardVector[i-1][j];
							boardVector[i-1][j] = -1;
						}
					}
				}
			}

			if (move == 'L'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < boardVector.size(); ++i)
				{
					for (int j = 0; j < boardVector[i].size(); ++j)
					{
						if (boardVector[i][j]== -1 && (j-1)>=0 )
						{
							boardVector[i][j] = boardVector[i][j-1];
							boardVector[i][j-1] = -1;
						}
					}
				}
			}

			if (move == 'R'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < boardVector.size(); ++i)
				{
					for (int j = 0; j < boardVector[i].size(); ++j)
					{
						if (boardVector[i][j]== -1 && (j+1)<boardVector[i].size() )
						{	
							boardVector[i][j] = boardVector[i][j+1];
							boardVector[i][j+1] = -1;
							return; 
							// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
						}
					}
				}
			}
		} // end of the file format 1.
	}

	// Checks whether the game is solved.
	bool BoardVector::isSolved() const
	{
		int curVal = 1;
		int rowValue = boardVector.size();
		int colValue = boardVector[0].size();

		if (game_format == 1)						// For HW1 format
		{

			for (int i = 0; i < rowValue; ++i){
		
				if(i == rowValue-1) 				// -1 represents blank tile. I reduce size, because last tile has to be blank. 
					colValue--;

				for (int j = 0; j < colValue; ++j)
					if(boardVector[i][j]!=curVal++)
						return false;	
			}

			return true;
		}

		else
		{
			for (int i = 0; i < rowValue; ++i)
			{
				if (i == rowValue-1) 		 		// -1 represents blank tile.It has to be at the lower right corner.
					--colValue;
			
				for (int j = 0; j < colValue; ++j)
				{
					if (boardVector[i][j] != 0) { 	 // 0 is the impossible tile.

						if (boardVector[i][j] != curVal++)
							return false;
					}
				}
			} 	

			return true;
		}
	}

	// Returns the cell content which belongs to parameter values.
	int BoardVector::operator()(int xIndex, int yIndex) const
	{
		if (xIndex >= 0 && yIndex >= 0 && xIndex < boardVector.size()  && yIndex < boardVector[0].size())
		{
			return boardVector.at(xIndex).at(yIndex);
		}

		else{

			cout << "Invalid index values" << endl;
			exit(1);
		}
	}

	// Compares two boards to each other, last move, number of moves and other data members are ignored.
	// == operator of vector class compares the vectors according to their elemets.
	bool BoardVector::operator==(const AbstractBoard& otherBoard) const
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
	void BoardVector::findEmptyNode(int& cur_i, int& cur_j) const{

		for (int i = 0; i < boardVector.size(); ++i)
		{
			for (int j = 0; j < boardVector[0].size(); ++j)
			{
				if(boardVector[i][j] == -1){  // -1 represents blank tile.
					cur_i = i;
					cur_j = j;
					return;
				}
			}
		}
	}

	// Returns value of column of the board
	int BoardVector::getCol() const
	{
		return boardVector[0].size();
	}

	// Returns value of row of board
	int BoardVector::getRow() const
	{
		return boardVector.size();
	}

}