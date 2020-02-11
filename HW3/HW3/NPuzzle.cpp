#include "NPuzzle.h"


// No parameter constructor.
// When you create an instance of NPuzzle, it initializes numberOfMoves value.
// Also, no parameter constructor of Board class works and it initializes boards, sets their size to a fix value.
NPuzzle::NPuzzle(){

	numberOfMoves = 0;
}

// Sets numberOfMoves value.
void NPuzzle::setNumberOfMoves(int move){

	numberOfMoves += move;
}

// Sets formatChoice value.
// This data member is used to decide which game (HW1 format or HW2 format) to play.
// There are two data member which represent game format. board1 represents format of HW1, board2 represents format of HW2.
// If user wants to play game whose format is HW2, board2 data member will be used. Otherwise, board1 will be used.
void NPuzzle::setFormatChoice(int format){

	formatChoice = format;
	if (formatChoice == 1)
		board1.set_format_choice(1);
	else
		board2.set_format_choice(2);

} 

// Prints current configuration on the screen. 
void NPuzzle::print() const{

	if (formatChoice == 1)
		board1.print();
	else
		board2.print();
}

// Prints a report whether the problem is solved and how many moves have been done.
void NPuzzle::printReport() const{

	cout << "Total number of moves " << numberOfMoves << endl;
	if (formatChoice == 1)
	{
		if (board1.isSolved() != true)
			cout << "Solution is not found" << endl;

		else
			cout << "Solution is found" << endl;
	}
	
	else 
	{
		if (board2.isSolved() != true)
			cout << "Solution is not found" << endl;

		else
			cout << "Solution is found" << endl;
	}
}

// Reads game board from file.
// It returns row*col of this board, because Shuffle command has to make size*size random moves.
// but I can't reach this value in main. That's way it returns this value.
const int NPuzzle::readFromFile(string fileName){

	return board2.readFromFile(fileName);
}

// Writes the current configuration to a file.
void NPuzzle::writeToFile(string fileName) const{

	board2.writeToFile(fileName);
}

// Makes size*size random moves.
void NPuzzle::shuffle(int numberOfRandomMoves){

	reset();
	for (auto i = 0; i < numberOfRandomMoves; ++i)	
		moveRandom();	
}

// Resets the current configuration to solution.
void NPuzzle::reset(){

	if (formatChoice == 1)
		board1.reset();
	else
		board2.reset();
}

// Sets the size values.
void NPuzzle::setsize(int rowValue, int colValue){

	if (formatChoice == 1)
		board1.setsize(rowValue,colValue);
	else
		board2.setsize(rowValue,colValue);
}

// If user plays game which has format of HW1, this function creates random board.
void NPuzzle::fillRandom(){

	board1.fillRandom();
}

// Makes a valid random move.
void NPuzzle::moveRandom(){

	int cur_i;
	int cur_j;
	int random;

	if (formatChoice == 2)
	{
		int ** board_arr = board2.getBoard();
		for (auto i = 0; i < 1; ++i)
		{

			random = rand() % 4; 				// There are four situations.
			board2.findEmptyNode(cur_i,cur_j);  // finds where the blank tile is.

			// 0 represents move up situation.
			if (random == 0)
			{
				// It checks if there is an empty and a suitable cell to move up.
				if (board2.checkValidty(cur_i-1,cur_j) && board_arr[cur_i-1][cur_j] != 0){
					board2.move('U');
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;				
			}

			// 1 represents move down situation.
			if (random == 1)
			{
				// It checks if there is an empty and a suitable cell to move down.
				if (board2.checkValidty(cur_i+1,cur_j) && board_arr[cur_i+1][cur_j] != 0){	
					board2.move('D');
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}

			// 2 represents move right situation.
			if (random == 2)
			{
				// It checks if there is an empty and a suitable cell to move right.
				if (board2.checkValidty(cur_i,cur_j+1) && board_arr[cur_i][cur_j+1] != 0){	
					board2.move('R');	
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}

			// 3 represents move left situation.
			if (random == 3)
			{
				// It checks if there is an empty and a suitable cell to move left.
				if (board2.checkValidty(cur_i,cur_j-1) && board_arr[cur_i][cur_j-1] != 0){	
					board2.move('L');		
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}
		}

	}

	else
	{	
		int ** board_arr = board1.getBoard();
		for (int i = 0; i < 1; ++i)
		{

			random = rand() % 4;				 // There are four situations.
			board1.findEmptyNode(cur_i,cur_j);   // finds where the blank tile is.

			// 0 represents move up situation.
			if (random == 0)
			{
				// It checks if there is an empty and a suitable cell to move up.
				if (board1.checkValidty(cur_i-1,cur_j)){
					board1.move('U');
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;				
			}

			// 1 represents move down situation.
			if (random == 1)
			{
				// It checks if there is an empty and a suitable cell to move down.
				if (board1.checkValidty(cur_i+1,cur_j)){	
					board1.move('D');
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}

			// 2 represents move right situation.
			if (random == 2)
			{
				// It checks if there is an empty and a suitable cell to move right.
				if (board1.checkValidty(cur_i,cur_j+1)){	
					board1.move('R');	
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}

			// 3 represents move left situation.
			if (random == 3)
			{
				// It checks if there is an empty and a suitable cell to move left.
				if (board1.checkValidty(cur_i,cur_j-1)){	
					board1.move('L');		
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}
		}
	}
	
}

// This is a private function to be used in intelligent move.
// If it is valid, it makes a move on the board which is given as parameter.
void NPuzzle::move(char move, int ** arr, int rowValue, int colValue){

	if (formatChoice == 2)
	{
		if (move == 'U')
		{
			for (int i = 0; i < rowValue; ++i)
			{
				for (int j = 0; j < colValue; ++j)
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
			for (int i = 0; i < rowValue; ++i)
			{
				for (int j = 0; j < colValue; ++j)
				{
					if (arr[i][j]== -1 && (i+1) < rowValue && arr[i+1][j] != 0)
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
			for (int i = 0; i < rowValue; ++i)
			{
				for (int j = 0; j < colValue; ++j)
				{
					if (arr[i][j]== -1 && (j-1) >= 0 && arr[i][j-1] != 0)
					{
						arr[i][j] = arr[i][j-1];
						arr[i][j-1] = -1;
					}
				}
			}
		}

		if (move == 'R')
		{
			for (int i = 0; i < rowValue; ++i)
			{
				for (int j = 0; j < colValue; ++j)
				{
					if (arr[i][j]== -1 && (j+1) < colValue && arr[i][j+1] != 0)
					{
						arr[i][j] = arr[i][j+1];
						arr[i][j+1] = -1;
						return; 
						// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
					}
					
				}
			}
		}
	}

	else
	{
		if (move == 'D'){

			for (int i = 0; i < rowValue; ++i)
			{
				for (int j = 0; j < colValue; ++j)
				{
					if (arr[i][j]== -1 && (i+1)<rowValue )
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

			for (int i = 0; i < rowValue; ++i)
			{
				for (int j = 0; j < colValue; ++j)
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
			for (int i = 0; i < rowValue; ++i)
			{
				for (int j = 0; j < colValue; ++j)
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
			
			for (int i = 0; i < rowValue; ++i)
			{
				for (int j = 0; j < colValue; ++j)
				{
					if (arr[i][j]== -1 && (j+1)<colValue )
					{
						arr[i][j] = arr[i][j+1];
						arr[i][j+1] = -1;
						return; 
						// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
					}
				}
			}
		}
	}
}

// This is a private function to be used in intelligent move.
const int NPuzzle::findCloseness(int ** arr, int rowValue, int colValue) const{

	int k=1;
	decltype(k) closeness =0 ;
	decltype(k) distanceFromColumn;
	decltype(k) distanceFromRow;
	decltype(k) totalMoveDistance;

	if (formatChoice == 2)
	{
		for (int i = 0; i < rowValue; ++i)
		{
			for (int j = 0; j < colValue; ++j)
			{
				if (arr[i][j] != 0 && arr[i][j] != k)	// if it equals to k, then it is in the right position.
				{
					for (int m = 0; m < rowValue; ++m)
					{
						for (int n = 0; n < colValue; ++n)
						{
							if (arr[m][n] == k)	// it finds where the current number placed.
							{
								distanceFromRow = abs(m-i) ; // I get the absolute  of fhe numbers,
								distanceFromColumn = abs(n-j) ; // because they can be negative.
								totalMoveDistance = distanceFromColumn + distanceFromRow ; 
								// It calculates how many moves it is away from its right position.
								closeness = closeness + totalMoveDistance ;
								// It calculates the sum of moves for all tiles.
							}
						}
					}
				}

				// If the current tile is not wall, look at the next tile.
				if (arr[i][j] != 0)
					++k;
			}
		}
	}


	else
	{
		for (int i = 0; i < rowValue; ++i)
		{
			for (int j = 0; j < colValue; ++j)
			{
				if (arr[i][j] != k)	// if it equals to k, then it is in the right position.
				{
					for (int m = 0; m < rowValue; ++m)
					{
						for (int n = 0; n < colValue; ++n)
						{
							if (arr[m][n] == k)	// it finds where the current number placed.
							{
								distanceFromRow = abs(m-i) ; // I get the absolute  of fhe numbers,
								distanceFromColumn = abs(n-j) ; // because they can be negative.
								totalMoveDistance = distanceFromColumn + distanceFromRow ; 
								// It calculates how many moves it is away from its right position.
								closeness = closeness + totalMoveDistance ;
								// It calculates the sum of moves for all tiles.
							}
						}
					}
				}

				++k;
			}
		}
	}
	
	return closeness;
}

// It makes an intelligent move for you. 
// This means, after the move, all the tiles are closer to their final positions.
const char NPuzzle::moveIntelligent(){


	char moveChoice;
	int rowValue;
	int colValue;
	int ** board_arr;

	if (formatChoice == 1)
	{
		rowValue = board1.getRow();
		colValue = board1.getCol();
		board_arr = board1.getBoard();
	}

	else
	{
		rowValue = board2.getRow();
		colValue = board2.getCol();
		board_arr = board2.getBoard();
	}
	

	// I create four copies of N-puzzle to find the situation which all tiles have minimum moves
	// to be placed to their right position.
	int ** arrUp = (int **)malloc(sizeof(int*)*rowValue);
	for (int i = 0; i < rowValue; ++i)
		arrUp[i] = (int*)malloc(sizeof(int)*colValue);

	int ** arrDown = (int **)malloc(sizeof(int*)*rowValue);
	for (int i = 0; i < rowValue; ++i)
		arrDown[i] = (int*)malloc(sizeof(int)*colValue);

	int ** arrLeft = (int **)malloc(sizeof(int*)*rowValue);
	for (int i = 0; i < rowValue; ++i)
		arrLeft[i] = (int*)malloc(sizeof(int)*colValue);

	int ** arrRight = (int **)malloc(sizeof(int*)*rowValue);
	for (int i = 0; i < rowValue; ++i)
		arrRight[i] = (int*)malloc(sizeof(int)*colValue);

	for (int i = 0; i < rowValue; ++i)
	{
		for (int j = 0; j < colValue; ++j)
		{
			arrUp[i][j] = board_arr[i][j];
			arrDown[i][j] = board_arr[i][j];
			arrLeft[i][j] = board_arr[i][j];
			arrRight[i][j] = board_arr[i][j];
		}
	}

	// They find how many moves are necessary for tiles to be placed to their correct positions.
	// I can't use normal move function here, because I use another array independent of current board.
	move('U',arrUp,rowValue,colValue);
	int closenessUp = findCloseness(arrUp,rowValue,colValue);

	move('D',arrDown,rowValue,colValue);
	int closenessDown = findCloseness(arrDown,rowValue,colValue);

	move('L',arrLeft,rowValue,colValue);
	int closenessLeft = findCloseness(arrLeft,rowValue,colValue);

	move('R',arrRight,rowValue,colValue);
	int closenessRight = findCloseness(arrRight,rowValue,colValue);

	int * closenessArray = (int*)malloc(sizeof(int)*(4));
	closenessArray[0] = closenessUp;
	closenessArray[1] = closenessDown;
	closenessArray[2] = closenessLeft;
	closenessArray[3] = closenessRight;

	// To find which has the minimum moves.
	int cur_i,cur_j;
 	int min;
	if (formatChoice == 1)
	{
		board1.findEmptyNode(cur_i,cur_j);
		min = rowValue*rowValue*rowValue;

		for (int i = 0; i < 4; ++i)
		{
			if (closenessArray[i] < min)
			{
				// First it checks if there is an empty cell for the desired move. 
				if(i==0)
					if(board1.checkValidty(cur_i-1,cur_j))
						min = closenessArray[i];
				if(i==1)
					if(board1.checkValidty(cur_i+1,cur_j))
						min = closenessArray[i];
				if(i==2)
					if(board1.checkValidty(cur_i,cur_j-1))
						min = closenessArray[i];
				if(i==3)
					if(board1.checkValidty(cur_i,cur_j+1))
						min = closenessArray[i];
			}
		}
	}

	else
	{
		board2.findEmptyNode(cur_i,cur_j);
		min = pow(colValue,rowValue)*colValue;
		for (int i = 0; i < 4; ++i)
		{
			if (closenessArray[i] < min)
			{
				// First it checks if there is an empty and suitable cell for the desired move. 
				if(i==0)
					if(board2.checkValidty(cur_i-1,cur_j) && board_arr[cur_i-1][cur_j] != 0)
						min = closenessArray[i];
				if(i==1)
					if(board2.checkValidty(cur_i+1,cur_j) && board_arr[cur_i+1][cur_j] != 0)
						min = closenessArray[i];
				if(i==2)
					if(board2.checkValidty(cur_i,cur_j-1) && board_arr[cur_i][cur_j-1] != 0)
						min = closenessArray[i];
				if(i==3)
					if(board2.checkValidty(cur_i,cur_j+1) && board_arr[cur_i][cur_j+1] != 0)
						min = closenessArray[i];
			}
		}
	}

	// According to the min value, make the movement.
	if (min == closenessArray[0])
	{	
		if (formatChoice == 1)
			board1.move('U');
		else
			board2.move('U');

		moveChoice = 'U';
	}

	else if (min == closenessArray[1])
	{
		if (formatChoice == 1)
			board1.move('D');
		else
			board2.move('D');

		moveChoice = 'D';
	}

	else if (min == closenessArray[2])
	{
		if (formatChoice == 1)
			board1.move('L');
		else
			board2.move('L');

		moveChoice = 'L';
	}

	else if (min == closenessArray[3])
	{
		if (formatChoice == 1)
			board1.move('R');
		else
			board2.move('R');

		moveChoice = 'R';
	}

	for (int i = 0; i < rowValue; ++i)
	{
		free(arrUp[i]);
		free(arrDown[i]);
		free(arrLeft[i]);
		free(arrRight[i]);
	}

	free(arrUp);
	free(arrDown);
	free(arrLeft);
	free(arrRight);
	free(closenessArray);

	return moveChoice;
}

// Makes a move according to the char parameter.(Left, Right, Up, Down)
void NPuzzle::move(char move){

	if (formatChoice == 1)
		board1.move(move);

	else
		board2.move(move);
}

// It detects whether the intelligent move gets stuck.
// If it gets stuck it returns true.
const bool NPuzzle::getStuck(char * arrChoice, char intelligentMoveChoice, int currentSize) const{

	//This array stores which moves intelligent move chooses.
	arrChoice[currentSize] = intelligentMoveChoice;

	// arrChoice must have  at least four elements to understand getstuck situation.Like : U,D,U,D... 
	if ((currentSize+1) > 3)
	{
		if(arrChoice[currentSize] == arrChoice[currentSize-2] && arrChoice[currentSize-1] == arrChoice[currentSize-3])
			return true;
	}

	return false;
}

// It gets you to the solution.
const int NPuzzle::solvePuzzle(){

	int number = 0;				// To calculates how many moves have been done.
	char intelligentMoveChoice;
	int curSize = -1;			// Index of the move choices.
	char * arrChoice = (char*)malloc(sizeof(char)*(1000));

	// Until the solution is found, make random and intelligent moves.
	if (formatChoice == 1)
	{
		while(!board1.isSolved()){

			do{

				intelligentMoveChoice = moveIntelligent();	
				++ curSize;											
				++number;
				board1.print();
				cout<<endl;

			} while(getStuck(arrChoice, intelligentMoveChoice, curSize)!=true && board1.isSolved()!=true);
			
			// Checked again if the game is solved, because loop may end due to solved game,
			// It should not move again until the check point(other while loop)
			if (board1.isSolved()!=true)
			{
				moveRandom();
				board1.print();
				cout<<endl;
				++number;
			}

			if (board1.isSolved()!=true)
			{
				moveRandom();
				board1.print();
				cout<<endl;
				++number;
			}

			if (board1.isSolved()!=true)
			{
				moveRandom();
				board1.print();
				cout<<endl;
				++number;
			}

			// It allocates memory again, because after random moves, stuck situation will be changed.
			// For instance, Last moves may be like this :U,D,U,D. 
			// After random moves, moves may be like this again : U,D..
			// So if arrChoice is not resetted, it can detect stuck situation again.
			char * arrChoice = (char*)malloc(sizeof(char)*(1000));
			curSize = -1;
		}
	}

	else
	{
		while(!board2.isSolved()){

			do{

				intelligentMoveChoice = moveIntelligent();
				++ curSize;
				++number;
				board2.print();
				cout<<endl;

			} while(getStuck(arrChoice, intelligentMoveChoice, curSize)!=true && board2.isSolved()!=true);
		

			// Checked again if the game is solved, because if loop ends due to solved game,
			// It should not move again until the check point(other while loop)
			if (board2.isSolved()!=true)
			{
				moveRandom();
				board2.print();
				cout<<endl;
				++number;
			}

			if (board2.isSolved()!=true)
			{
				moveRandom();
				board2.print();
				cout<<endl;
				++number;
			}

			if (board2.isSolved()!=true)
			{
				moveRandom();
				board2.print();
				cout<<endl;
				++number;
			}

			// It allocates memory again, because after random moves, stuck situation will be changed.
			// For instance, Last moves may be like this :U,D,U,D. 
			// After random moves, moves may be like this again : U,D..
			// So if arrChoice is not resetted, it can detect stuck situation again.
			char * arrChoice = (char*)malloc(sizeof(char)*(1000));
			curSize = -1;
		}
	}
	

	free(arrChoice);
	return number;
}

// Checks whether the game is solved.
const bool NPuzzle::isSolved() const{

	if (formatChoice == 1)
		return board1.isSolved();
	else
		return board2.isSolved();	
}

// This function is valid for HW1.
// It tests whether the game can be solvable. 
// To understand that , it uses number of inversions and where the blank tile is.
const bool NPuzzle::checkSolvable() const{

	int numberOfInversions = board1.getInversionNumber();
	int blankPosition = board1.findBlankPosition();
	int rowValue = board1.getRow();

	// if game size is odd, then number of inversions must be even.
	if (rowValue % 2 == 1 && numberOfInversions % 2 == 0)
	{
	  	return true;
	}  

	// if game size is even, there are two situations.
	// One of them is, if blank tile position is even when counted from bottom to top, number of inversions must be odd.
	else if (rowValue % 2 == 0 && blankPosition % 2 == 0 && numberOfInversions % 2 == 1)
	{
		return true;
	}

	// Other one is, if blank tile position is odd when counted from bottom to top, number of inversions must be even.
	else if (rowValue % 2 == 0 && blankPosition % 2 == 1 && numberOfInversions % 2 == 0)
	{
		return true;
	}

	// if none of them is suitable, then game can't be solved.
	else
		return false;
}

// No parameter constructor.
NPuzzle::Board::Board(){

	arr = (int **)malloc(sizeof(int*)*3);
	for (int i = 0; i < 3; ++i) 				// row
		arr[i] = (int*)malloc(sizeof(int)*3);   // column

	row = 3;
	col = 3;
}

// Constructor to initialize data members according to function parameters.
NPuzzle::Board::Board(int rowValue, int colValue){

	arr = (int **)malloc(sizeof(int*)*rowValue);
	for (int i = 0; i < rowValue; ++i) 				  // row
		arr[i] = (int*)malloc(sizeof(int)*colValue);  // column

	row = rowValue;
	col = colValue;
}

// Returns row value.
inline int NPuzzle::Board::getRow() const{

	return row;
}

// Returns column value.
inline int NPuzzle::Board::getCol() const{

	return col;
}

// Returns board.
int ** NPuzzle::Board::getBoard() const{

	return arr;
}

// Sets format choice. 
// This data member is used to decide which game (HW1 format or HW2 format) to play.
void NPuzzle::Board::set_format_choice(int format){

	format_choice = format;
}

// Prints the current configuration on the screen.
void NPuzzle::Board::print() const{


	if (format_choice == 1)
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
// It returns row*col of this board, because Shuffle command has to make size*size random moves.
// but I can't reach this value in main. That's way it returns this value.
const int NPuzzle::Board::readFromFile(string fileName){

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
    	setsize(rowValue,colValue);

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

	return row*col;
}

// Writes the current configuration to a file.
void NPuzzle::Board::writeToFile(string fileName) const{

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
void NPuzzle::Board::reset(){

	// It takes the board to the final state.
	int curVal = 1;
	if (format_choice == 1)
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
void NPuzzle::Board::setsize(int rowValue, int colValue){

	if (rowValue > 2 && rowValue < 9 && colValue > 2 && colValue <9) 
	{
		row = rowValue;
 		col = colValue;

 		arr = (int **)malloc(sizeof(int*)*row);
		for (int i = 0; i < row; ++i) 				  // row
			arr[i] = (int*)malloc(sizeof(int)*col);   // column	
	}	
}

// Makes a move according to the char parameter(Right, Left, Up, Down)
void NPuzzle::Board::move(char move){

	if (format_choice == 2)
	{

		if (move == 'U')
		{
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
const bool NPuzzle::Board::isSolved() const{

	int curVal = 1;
	int rowValue = row;
	int colValue = col;

	if (format_choice == 1)				// For HW1 format
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

// It finds the location of blank tile.
void NPuzzle::Board::findEmptyNode(int& cur_i, int& cur_j) const{

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if(arr[i][j] == -1){  // -1 represents blank tile.
				cur_i = i;
				cur_j = j;
				return;
			}
		}
	}
} 

// It is a helper function to be used in other functions. 
// It will be used to check if there is an empty cell for the current movement
inline const bool NPuzzle::Board::checkValidty(int i,int j) const{
	return (i<row && i>=0 && j<col && j>=0);
}

// It creates a random game board.
void NPuzzle::Board::fillRandom(){

	int max = (row*col) - 1;
	int * arr2 = (int*)malloc(sizeof(int)*(max+1));
	for (int i = 0; i < max; ++i)
		arr2[i] = i+1;
	arr2[max] = -1; // empty cell

	bool * checked = (bool*)malloc(sizeof(bool)*(max+1));
	for (int i = 0; i < max+1; ++i)
		checked[i] = false;

	int random;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			random = rand() % (max +1);
			while(checked[random])
				random = rand() % (max+1);
			arr[i][j] = arr2[random];
			checked[random] = true;
		}
	}

	free(arr2);
	free(checked);	
}


// This function is valid for HW1.
// It is a helper function to understand whether the game can be solvable.
const int NPuzzle::Board::getInversionNumber() const{


	int numberOfInversions = 0;
	int j = 0;
	int k = 0;

	int * array = (int*)malloc(sizeof(int)*(row*col));

	// It transforms 2-dimensional array into one-dimensional.
	for (int i = 0; i < (row*col); ++i)
	{
	 	if (arr[j][k] != -1)
	 	{
	 		array[i] = arr[j][k];
	 		++k;

	 		if (k == row )
	 		{
	 			k=0;
	 			++j;
	 		}
	 	}

	 	else{

	 		array[i] = -1;
	 		++k;

	 		if (k == row)
	 		{
	 			k=0;
	 			++j;
	 		}

	 	}
	} 

	// If array[i] > array[j] and i<j, there is a inversion.
	for (int i = 0; i < (row*col -1); ++i)
	{
		for (int j= i + 1; j < row*col; ++j)
		{
			if (array[i] > array[j] && array[i] != -1 && array[j] != -1)
			{
				++ numberOfInversions;
			}
		}
	}

	free(array);
	return numberOfInversions;
}


// This function is valid for HW1.
// It is a helper function to understand whether the game can be solvable.
// It finds where the blank tile is. It counts from bottom to top.
const int NPuzzle::Board::findBlankPosition() const{

	int place;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (arr[i][j] == -1)
			{
				place = row - i ; 
			}
		}
	}

	return place;
}