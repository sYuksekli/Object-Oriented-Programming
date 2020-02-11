#include "NPuzzle.h"

int NPuzzle::Board::numberOfBoards = 0;

// No parameter constructor.
// When you create an instance of NPuzzle, it adds a board object to vector. 
// No parameter constructor of Board class works and it initializes last move, number of moves.
NPuzzle::NPuzzle(){

	boards.resize(1);
}

// Sets game_format value.
// This data member is used to decide which game (HW1 format or HW2 format) to play. 
void NPuzzle::setGameFormat(int format){

	boards.back().set_game_format(format);
}

// Prints current configuration on the screen. 
void NPuzzle::print() const{
	boards.back().print();
}

// Prints a report whether the problem is solved and how many moves have been done.
void NPuzzle::printReport() const{

	cout << "Total number of moves " << boards.back().numberOfMoves() << endl;

	if (boards.back().isSolved() != true)
		cout << "Solution is not found" << endl;

	else
		cout << "Solution is found" << endl;
}

// Reads game board from file.
// It returns row*col of this board, because Shuffle command has to make size*size random moves.
// but I can't reach this value in main. That's way it returns this value.
int NPuzzle::readFromFile(string fileName){

	boards.erase(boards.begin(),boards.end()-1);	// Resize to 1
	int numForShuffle;
	numForShuffle = boards.back().readFromFile(fileName); 
	return numForShuffle;
}

// Writes the current configuration to a file.
void NPuzzle::writeToFile(string fileName) const{

	boards.back().writeToFile(fileName);
}

// Makes size*size random moves.
void NPuzzle::shuffle(int numberOfRandomMoves){

	boards.erase(boards.begin(),boards.end()-1);	// Resize to 1
	reset();
	for (auto i = 0; i < numberOfRandomMoves; ++i)	
		moveRandom();	
}

// Resets the current configuration to solution.
void NPuzzle::reset(){

	boards.back().reset();
}

// Sets the size values.
void NPuzzle::setsize(int rowValue, int colValue){

	boards.back().setSize(rowValue,colValue);
}

// If user plays game which has format of HW1, this function creates random board.
void NPuzzle::fillRandom(){

	boards.back().fillRandom();
}

// Makes a valid random move.
void NPuzzle::moveRandom(){

	boards.erase(boards.begin(),boards.end()-1);	// Resize to 1
	int cur_i;
	int cur_j;
	int random;
	int format = boards.back().getGameFormat();

	if (format == 2)
	{
		for (auto i = 0; i < 1; ++i)
		{
			vector<vector<int>> boardVec = boards.back().getBoard();
			random = rand() % 4; 				   		// There are four situations.
			boards.back().findEmptyNode(cur_i,cur_j);  // finds where the blank tile is.

			// 0 represents move up situation.
			if (random == 0)
			{
				// It checks if there is an empty and a suitable cell to move up.
				if (boards.back().checkValidty(cur_i-1,cur_j) && boardVec[cur_i-1][cur_j] != 0){
					move('U');
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;				
			}

			// 1 represents move down situation.
			if (random == 1)
			{
				// It checks if there is an empty and a suitable cell to move down.
				if (boards.back().checkValidty(cur_i+1,cur_j) && boardVec[cur_i+1][cur_j] != 0){	
					move('D');
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}

			// 2 represents move right situation.
			if (random == 2)
			{
				// It checks if there is an empty and a suitable cell to move right.
				if (boards.back().checkValidty(cur_i,cur_j+1) && boardVec[cur_i][cur_j+1] != 0){	
					move('R');	
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}

			// 3 represents move left situation.
			if (random == 3)
			{
				// It checks if there is an empty and a suitable cell to move left.
				if (boards.back().checkValidty(cur_i,cur_j-1) && boardVec[cur_i][cur_j-1] != 0){	
					move('L');		
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}
		}

	}

	else
	{	
		for (int i = 0; i < 1; ++i)
		{

			random = rand() % 4;				 		// There are four situations.
			boards.back().findEmptyNode(cur_i,cur_j);   // finds where the blank tile is.

			// 0 represents move up situation.
			if (random == 0)
			{
				// It checks if there is an empty and a suitable cell to move up.
				if (boards.back().checkValidty(cur_i-1,cur_j)){
					move('U');
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;				
			}

			// 1 represents move down situation.
			if (random == 1)
			{
				// It checks if there is an empty and a suitable cell to move down.
				if (boards.back().checkValidty(cur_i+1,cur_j)){	
					
					move('D');
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}

			// 2 represents move right situation.
			if (random == 2)
			{
				// It checks if there is an empty and a suitable cell to move right.
				if (boards.back().checkValidty(cur_i,cur_j+1)){	
					move('R');	
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}

			// 3 represents move left situation.
			if (random == 3)
			{
				// It checks if there is an empty and a suitable cell to move left.
				if (boards.back().checkValidty(cur_i,cur_j-1)){	
					move('L');		
				}

				// If it is not, it reduces the number of i to repeat the move.
				else
					--i;
			}
		}
	}
}

// Makes a move according to the char parameter.(Left, Right, Up, Down)
void NPuzzle::move(char move){

	boards.erase(boards.begin(),boards.end()-1);	// Resize to 1
	boards.back().move(move);
	boards.back().setNumberOfMoves(1);				// number of moves are increased.
	boards.back().setLastMove(move);				// update last move.
}

// It gets you to the solution.
// Parameter is needed for print and move function.
void NPuzzle::solvePuzzle(int format){

	int checkEquality;
	bool solved = false;
	char move;

	int currentIndex = 0;
	int currentMove = boards.at(currentIndex).numberOfMoves();
	
	cout << endl;
	cout << "Last move was " << boards.at(currentIndex).lastMove() << endl;
	cout << "Number of moves " << boards.at(currentIndex).numberOfMoves() << endl;
	cout << endl;
	

	while(solved != true && currentIndex != boards.size()){

		// Create board object four times.
		for (int i = 0; i < 4; ++i)
		{
			NPuzzle::Board board = boards[currentIndex];

			// Apply all moves to the taken board.
			if (i==0)
			{	
				move = 'R';
				board.setLastMove(move);
				board.setNumberOfMoves(1);
				board.move(move);
			}

			if (i==1)
			{	
				move = 'L';
				board.setLastMove(move);
				board.setNumberOfMoves(1);
				board.move(move);
			}

			if (i==2)
			{	
				move = 'U';
				board.setLastMove(move);
				board.setNumberOfMoves(1);
				board.move(move);
			}

			if (i==3)
			{	
				move = 'D';
				board.setLastMove(move);
				board.setNumberOfMoves(1);
				board.move(move);
			}

			checkEquality = 0;
			if (solved != true)
			{
				for (int i = 0; i < boards.size(); ++i)
					if (boards[i] == board)
						checkEquality = 1;

				// If this board doesn't exist in the vector, push back this board into the vector.
				if (checkEquality!=1){
					boards.push_back(board);

					if (board.isSolved() == true){	// If pushed object is the solution, don't enter the loop again.
						solved = true;				// Solution is found.
						i = 4;
					}								

					cout << "Last move was " << board.lastMove() << endl;
					cout << "Number of moves " << board.numberOfMoves() << endl;
 					board.print();
					cout << endl;
				}
			}
		}

		++currentIndex;
	}
	
}

// Prints the current configuration on the screen.
ostream& operator<<(ostream& outputStream, const NPuzzle& puzzle){

	int rowValue = puzzle.boards.back().getRowOfBoard();
	int colValue = puzzle.boards.back().getColOfBoard();
	const vector<vector<int>> boardVec = puzzle.boards.back().getBoard();
	int format = puzzle.boards.back().getGameFormat();

	if (format == 2)
	{
		for (int i = 0; i < rowValue; ++i)
		{
			for (int j = 0; j < colValue; ++j)
			{
				if(boardVec[i][j] == -1) 
					outputStream << "bb" <<" ";	 // if it is blank tile, print as 'bb' to the screen.

				else if (boardVec[i][j] == 0)
					outputStream << "00" <<" ";	 // It represents walls.
			
				else{

					if (boardVec[i][j] < 10)
						outputStream <<"0"<<boardVec[i][j] <<" ";  // For one-digit numbers.
					else
						outputStream << boardVec[i][j] <<" ";
				}
			}

			outputStream << endl;
		}
	}

	else
	{
		for (int i = 0; i < rowValue; ++i)
		{
			for (int j = 0; j < colValue; ++j)
			{
				if(boardVec[i][j]==-1) 		// if it is blank tile, don't print to the screen.
					outputStream << "  ";
				else
					outputStream << boardVec[i][j] <<" ";
			}

			outputStream << endl;
		}
	}
	

	return outputStream;
}

// Reads the current configuration from istream object.
istream& operator>>(istream& inputStream, NPuzzle& puzzle){

	int rowValue = 0;
	int colValue = 0;

	string line;
	string line2;
	string word;
	string wordd;


	const auto blankStr = "bb";
	while (getline (inputStream,line)){         // To find number of rows
       	++ rowValue;
 
       	stringstream strStream(line);
       	while ( strStream >> word )     		// To find number of columns
			++ colValue;	
    }

    colValue = colValue / rowValue;
   
    // number of the current row and column can be different from size of the shape file.
   	// So it sets size of the board.
   	puzzle.setsize(rowValue,colValue);

	int i = 0; // row
	int j = 0; // col

	// These two lines below is needed for using inputStream object again from the beginning of the file.
	inputStream.clear();
	inputStream.seekg(0,inputStream.beg);
	while (getline(inputStream,line2)){

		cout << line2 << endl;								// It prints shape file to the screen.

		stringstream strStream2(line2);
		while( strStream2 >> wordd){

			if (wordd.compare(blankStr) == 0)
				puzzle.boards.back().setBoard(i,j,-1);		// Update content of board.
					
			else{
				int value = stoi(wordd);
				puzzle.boards.back().setBoard(i,j,value);	// Update content of board.
			}
				
			++j;
		}

		j=0;
		++i;	
	}

	return inputStream;
}


// Checks whether the game is solved.
bool NPuzzle::isSolved() const{

	return boards.back().isSolved();	
}

// This function is valid for HW1.
// It tests whether the game can be solvable. 
// To understand that , it uses number of inversions and where the blank tile is.
bool NPuzzle::checkSolvable() const{

	int numberOfInversions = boards.back().getInversionNumber();
	int blankPosition = boards.back().findBlankPosition();
	int size = boards.back().getRowOfBoard();	// row = column for the HW1 format.	

	// if game size is odd, then number of inversions must be even.
	if (size % 2 == 1 && numberOfInversions % 2 == 0)
	{
	  	return true;
	}  

	// if game size is even, there are two situations.
	// One of them is, if blank tile position is even when counted from bottom to top, number of inversions must be odd.
	else if (size % 2 == 0 && blankPosition % 2 == 0 && numberOfInversions % 2 == 1)
	{
		return true;
	}

	// Other one is, if blank tile position is odd when counted from bottom to top, number of inversions must be even.
	else if (size % 2 == 0 && blankPosition % 2 == 1 && numberOfInversions % 2 == 0)
	{
		return true;
	}

	// if none of them is suitable, then game can't be solved.
	else
		return false;
}


// No parameter constructor.
NPuzzle::Board::Board(){

	LastMove = 'S';
	NumberOfMoves = 0;
	++numberOfBoards;
}

// Constructor to initialize data members according to function parameters.
NPuzzle::Board::Board(vector<vector<int>> & vect,int numberOfMoves, int lastMove){

	boardVector = vect;
	LastMove = lastMove;
	NumberOfMoves = numberOfMoves;
	++numberOfBoards;
}

// Returns the number of boards created so far.
int NPuzzle::Board::NumberOfBoards(){
	return numberOfBoards;
}

// Returns the last move. If there is no last move, returns S.		
char NPuzzle::Board::lastMove() const{
	if (LastMove!= 'D' && LastMove!= 'U' && LastMove!= 'L' && LastMove!= 'R')
		return 'S';

	return LastMove;
}

// Return number of moves 
inline int NPuzzle::Board::numberOfMoves() const{
	return NumberOfMoves;
}

// Returns value of row of board
int NPuzzle::Board::getRowOfBoard() const
{
	return boardVector.size();
}

// Returns value of column of the board
int NPuzzle::Board::getColOfBoard() const
{
	return boardVector[0].size();
}

// Returns board vector.
const vector<vector<int>> & NPuzzle::Board::getBoard() const{

	return boardVector;
}

// Return game format(HW1 format or HW2 format)
inline int NPuzzle::Board::getGameFormat() const{

	return game_format;
}

// Sets the board according to the given parameters. (Indexes and the value to be inserted in that location.)
void NPuzzle::Board::setBoard(int xIndex, int yIndex, int value){

	boardVector.at(xIndex).at(yIndex) = value;
}

// Sets last move.
void NPuzzle::Board::setLastMove(char move){

	LastMove = move;
}

// Sets the number of moves that the current board made.
void NPuzzle::Board::setNumberOfMoves(int numOfMoves){

	NumberOfMoves += numOfMoves;
}

// Sets format choice. 
// This data member is used to decide which game (HW1 format or HW2 format) to play.
void NPuzzle::Board::set_game_format(int format){

	game_format = format;
}

// Prints the current configuration on the screen.
void NPuzzle::Board::print() const{


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
// It returns row*col of this board, because Shuffle command has to make size*size random moves.
// but I can't reach this value in main. That's way it returnss this value.
int NPuzzle::Board::readFromFile(string fileName){

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

	return rowValue*colValue;
}

// Writes the current configuration to a file.
void NPuzzle::Board::writeToFile(string fileName) const{

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
void NPuzzle::Board::reset(){

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
void NPuzzle::Board::setSize(int rowValue, int colValue){


	if (rowValue > 2 && rowValue < 10 && colValue > 2 && colValue < 10) 
	{	
		boardVector.erase(boardVector.begin(),boardVector.end());
		boardVector.resize(rowValue);

		for (int i = 0; i < boardVector.size(); ++i)
			boardVector[i].erase(boardVector[i].begin(),boardVector[i].end());

 		for (int i = 0; i <boardVector.size(); ++i)
 			boardVector[i].resize(colValue);
	}	

	else
	{
		cout << "Illegal size values" << endl;
		exit(1);
	}
}

// Makes a move according to the char parameter(Right, Left, Up, Down)
void NPuzzle::Board::move(char move){

	if (game_format == 2)
	{

		if (move == 'U')
		{
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
bool NPuzzle::Board::isSolved() const{

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

// It finds the location of blank tile.
void NPuzzle::Board::findEmptyNode(int& cur_i, int& cur_j) const{

	for (int i = 0; i < boardVector.size(); ++i)
	{
		for (int j = 0; j < boardVector[i].size(); ++j)
		{
			if(boardVector[i][j] == -1){  	// -1 represents blank tile.
				cur_i = i;
				cur_j = j;
				return;
			}
		}
	}
} 

// It is a helper function to be used in other functions. 
// It will be used to check if there is an empty cell for the current movement.
bool NPuzzle::Board::checkValidty(int i,int j) const{
	return (i<boardVector.size() && i>=0 && j<boardVector[0].size() && j>=0);
}

// It creates a random game board.
void NPuzzle::Board::fillRandom(){

	int rowValue = boardVector.size();
	int colValue = boardVector[0].size();
	int max = (rowValue*colValue) - 1;
	int * arr2 = new int[max+1];
	for (int i = 0; i < max; ++i)
		arr2[i] = i+1;
	arr2[max] = -1; // empty cell

	bool * checked = new bool[max+1];
	for (int i = 0; i < max+1; ++i)
		checked[i] = false;

	int random;
	for (int i = 0; i < rowValue; ++i)
	{
		for (int j = 0; j < colValue; ++j)
		{
			random = rand() % (max +1);
			while(checked[random])
				random = rand() % (max+1);
			boardVector[i][j] = arr2[random];
			checked[random] = true;
		}
	}

	delete [] arr2;
	delete [] checked;	
}


// This function is valid for HW1.
// It is a helper function to understand whether the game can be solvable.
int NPuzzle::Board::getInversionNumber() const{


	int numberOfInversions = 0;
	decltype(numberOfInversions) j = 0;
	decltype(numberOfInversions) k = 0;
	decltype(numberOfInversions) rowValue = boardVector.size();
	decltype(numberOfInversions) colValue = boardVector[0].size();
	int * array = new int[rowValue*colValue];
	// It transforms 2-dimensional array into one-dimensional.
	for (int i = 0; i < (rowValue*colValue); ++i)
	{
	 	if (boardVector[j][k] != -1)
	 	{
	 		array[i] = boardVector[j][k];
	 		++k;

	 		if (k == rowValue )
	 		{
	 			k=0;
	 			++j;
	 		}
	 	}

	 	else{

	 		array[i] = -1;
	 		++k;

	 		if (k == rowValue)
	 		{
	 			k=0;
	 			++j;
	 		}

	 	}
	} 

	// If array[i] > array[j] and i<j, there is a inversion.
	for (int i = 0; i < (rowValue*colValue -1); ++i)
	{
		for (int j= i + 1; j < rowValue*colValue; ++j)
		{
			if (array[i] > array[j] && array[i] != -1 && array[j] != -1)
			{
				++ numberOfInversions;
			}
		}
	}

	delete [] array;
	return numberOfInversions;
}


// This function is valid for HW1.
// It is a helper function to understand whether the game can be solvable.
// It finds where the blank tile is. It counts from bottom to top.
int NPuzzle::Board::findBlankPosition() const{

	int place;
	for (int i = 0; i < boardVector.size(); ++i)
	{
		for (int j = 0; j < boardVector[0].size(); ++j)
		{
			if (boardVector[i][j] == -1)
			{
				place = boardVector.size() - i ; 
			}
		}
	}

	return place;
}

// Returns the cell content which belongs to parameter values.
int NPuzzle::Board::operator()(int xIndex, int yIndex) const{

	if (xIndex >= 0 && yIndex >= 0 && xIndex < getRowOfBoard()  && yIndex < getColOfBoard())
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
bool NPuzzle::Board::operator==(const NPuzzle::Board& otherBoard) const{

	if (boardVector == otherBoard.getBoard())
		return true;
	else
		return false;
}