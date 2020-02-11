#include "AbstractBoard.h"

namespace GtuGame{

	int AbstractBoard::numberOfBoards = 0;

	// No parameter constructor
	AbstractBoard::AbstractBoard(){

		LastMove = 'S';
		NumberOfMoves = 0;
		game_format = -1;
		++numberOfBoards;
	}

	// Sets format choice. 
	// This data member is used to decide which game (HW1 format or HW2 format) format will be used.
	void AbstractBoard::set_game_format(int format)
	{
		game_format = format;
	}	

	// Returns the number of boards created so far.
	int AbstractBoard::NumberOfBoards()
	{
		return numberOfBoards;
	}

	// Returns the last move. If there is no last move, returns S.	
	char AbstractBoard::lastMove() const
	{
		return LastMove;
	}
	
	// Return number of moves 
	int AbstractBoard::numberOfMoves() const
	{
		return NumberOfMoves;
	}
}