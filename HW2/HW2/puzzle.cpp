#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


// This function is valid for both HW1 and HW2.
// This function tests whether the problem is solved. 
// If it equals to the final solution, it returns true.
const bool checkSolved(int ** arr,int row, int col, int fileFormat)
{	

	int curVal = 1;
	if (fileFormat == 1)	// For HW1 format
	{

		for (int i = 0; i < row; ++i){
		
			if(i == row-1) // -1 represents blank tile. I reduce size, because last tile has to be blank. 
				col--;

			for (int j = 0; j < col; ++j)
				if(arr[i][j]!=curVal++)
					return false;	
		}

		return true;
	}

	else{	// For HW2 format

		for (int i = 0; i < row; ++i)
		{
			if (i == row-1)  // -1 represents blank tile.It has to be at the lower right corner.
				--col;
			
			for (int j = 0; j < col; ++j)
			{

				if (arr[i][j] != 0) { // 0 is the impossible tile.

					if (arr[i][j] != curVal++)
						return false;
				}
			}
		} 	

		return true;
	}
}


// This function is valid for both HW1 and HW2.
// It finds the location of blank tile.
void findEmptyNode(int **arr, int row, int col, int * cur_i, int *cur_j){

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if(arr[i][j] == -1){  // -1 represents blank tile.
				*cur_i = i;
				*cur_j = j;
				return;
			}
		}
	}
}


// This function is valid for HW1.
// It allocates memory.
int ** create2DMatrix(int size)
{
	int ** arr = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; ++i) // row
		arr[i] = (int*)malloc(sizeof(int)*size); // column
	return arr;
}


// This function is valid for both HW1 and HW2.
// It is a helper function to be used in other functions. 
// It will be used to check if there is an empty cell for the current movement.
inline const bool checkValidty(int ** arr, int row, int col, int i,int j){
	return (i<row && i>=0 && j<col && j>=0);
}


// This function is valid for HW1.
// It creates a random game board.
void fillRandom(int ** arr, int size)
{
	int max = (size*size) - 1;
	int * arr2 = (int*)malloc(sizeof(int)*(max+1));
	for (int i = 0; i < max; ++i)
		arr2[i] = i+1;
	arr2[max] = -1; // empty cell

	bool * checked = (bool*)malloc(sizeof(bool)*(max+1));
	for (int i = 0; i < max+1; ++i)
		checked[i] = false;

	int random;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
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
// It prints N-puzzle to the screen.
void print2DMatrix(int ** arr,int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(arr[i][j]==-1) // if it is blank tile, don't print to the screen.
				cout << "  ";
			else
				cout << arr[i][j] <<" ";
		}

		cout << endl;
	}
}


// This function is valid for HW2.
// It prints N-puzzle to the screen.
void print2DMatrix(int ** arr,int row, int col)
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


// This function is valid for HW1.
// It moves the blank tile down, if there is a room.
void moveDown(int ** arr,int size){

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i][j]== -1 && (i+1)<size )
			{
				arr[i][j] = arr[i+1][j];
				arr[i+1][j] = -1;
				return;	
				// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
			}
		}
	}
}


// This function is valid for HW2.
// It moves the blank tile down, if there is a suitable room.
void moveDown(int ** arr,int row, int col){

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


// This function is valid for HW1.
// It moves the blank tile up, if there is a room.
void moveUp(int ** arr,int size){

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i][j]== -1 && (i-1)>=0 )
			{
				arr[i][j] = arr[i-1][j];
				arr[i-1][j] = -1;
			}
		}
	}
}


// This function is valid for HW2.
// It moves the blank tile up, if there is a suitable room.
void moveUp(int ** arr, int row, int col){

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


// This function is valid for HW1.
// It moves the blank tile left, if there is a room.
void moveLeft(int ** arr,int size){

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i][j]== -1 && (j-1)>=0 )
			{
				arr[i][j] = arr[i][j-1];
				arr[i][j-1] = -1;
			}
		}
	}
}


// This function is valid for HW2.
// It moves the blank tile left, if there is a suitable room.
void moveLeft(int ** arr, int row, int col){

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


// This function is valid for HW1.
// It moves the blank tile right, if there is a room.
void moveRight(int ** arr,int size){

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i][j]== -1 && (j+1)<size )
			{
				arr[i][j] = arr[i][j+1];
				arr[i][j+1] = -1;
				return; 
				// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
			}
		}
	}
}


// This function is valid for HW2.
// It moves the blank tile right, if there is a suitable room.
void moveRight(int ** arr, int row, int col){

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


// This function is valid for HW1.
// It is a helper function to use in intelligent move funciton.
int findCloseness(int **arr, int size){

	int k=1;
	int closeness =0 ;

	int distanceFromColumn;
	int distanceFromRow;
	int totalMoveDistance;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i][j] != k)	// if it equals to k, then it is in the right position.
			{
				for (int m = 0; m < size; ++m)
				{
					for (int n = 0; n < size; ++n)
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

	return closeness;
}


// This function is valid for HW2.
// It is a helper function to use in intelligent move funciton.
int findCloseness(int **arr, int row, int col){

	int k=1;
	decltype(k) closeness =0 ;

	decltype(k) distanceFromColumn;
	decltype(k) distanceFromRow;
	decltype(k) totalMoveDistance;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (arr[i][j] != 0 && arr[i][j] != k)	// if it equals to k, then it is in the right position.
			{
				for (int m = 0; m < row; ++m)
				{
					for (int n = 0; n < col; ++n)
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

			if (arr[i][j] != 0) // If the current tile is not wall, look at the next tile.
				++k;
		}
	}

	return closeness;
}


// This function is valid for HW1.
// It makes an intelligent move for you. 
//This means after the move, all the tiles are closer to their final positions.
const char IntelligentMove(int ** arr,int size){

	char moveChoice;

	// I create four copies of N-puzzle to find the situation which all tiles have minimum moves
	// to be placed to their right position.
	int ** arrUp = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; ++i)
		arrUp[i] = (int*)malloc(sizeof(int)*size);

	int ** arrDown = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; ++i)
		arrDown[i] = (int*)malloc(sizeof(int)*size);

	int ** arrLeft = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; ++i)
		arrLeft[i] = (int*)malloc(sizeof(int)*size);

	int ** arrRight = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; ++i)
		arrRight[i] = (int*)malloc(sizeof(int)*size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			arrUp[i][j] = arr[i][j];
			arrDown[i][j] = arr[i][j];
			arrLeft[i][j] = arr[i][j];
			arrRight[i][j] = arr[i][j];
		}
	}

	// They find how many moves are necessary for tiles to be placed to their correct positions.
	moveUp(arrUp,size);
	int closenessUp = findCloseness(arrUp, size);

	moveDown(arrDown,size);
	int closenessDown = findCloseness(arrDown, size);

	moveLeft(arrLeft,size);
	int closenessLeft = findCloseness(arrLeft, size);

	moveRight(arrRight,size);
	int closenessRight = findCloseness(arrRight, size);

	int * closenessArray = (int*)malloc(sizeof(int)*(4));
	closenessArray[0] = closenessUp;
	closenessArray[1] = closenessDown;
	closenessArray[2] = closenessLeft;
	closenessArray[3] = closenessRight;

	// To find which has the minimum moves.
	int cur_i,cur_j;
	findEmptyNode(arr,size,size,&cur_i,&cur_j);

	int min = size*size*size;
	for (int i = 0; i < 4; ++i)
	{
		if (closenessArray[i] < min)
		{
			// First it checks if there is an empty cell for the desired move. 
			if(i==0)
				if(checkValidty(arr,size,size,cur_i-1,cur_j))
					min = closenessArray[i];
			if(i==1)
				if(checkValidty(arr,size,size,cur_i+1,cur_j))
					min = closenessArray[i];
			if(i==2)
				if(checkValidty(arr,size,size,cur_i,cur_j-1))
					min = closenessArray[i];
			if(i==3)
				if(checkValidty(arr,size,size,cur_i,cur_j+1))
					min = closenessArray[i];
		}
	}
	
	if (min == closenessArray[0])
	{
		moveUp(arr,size);
		moveChoice = 'U';
	}

	else if (min == closenessArray[1])
	{
		moveDown(arr,size);
		moveChoice = 'D';
	}

	else if (min == closenessArray[2])
	{
		moveLeft(arr,size);
		moveChoice = 'L';
	}

	else if (min == closenessArray[3])
	{
		moveRight(arr,size);
		moveChoice = 'R';
	}

	for (int i = 0; i < size; ++i)
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


// This function is valid for HW2.
// It makes an intelligent move for you. 
// This means after the move, all the tiles are closer to their final positions.
const char IntelligentMove(int ** arr,int row, int col){


	char moveChoice;

	// I create four copies of N-puzzle to find the situation which all tiles have minimum moves
	// to be placed to their right position.
	int ** arrUp = (int **)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; ++i)
		arrUp[i] = (int*)malloc(sizeof(int)*col);

	int ** arrDown = (int **)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; ++i)
		arrDown[i] = (int*)malloc(sizeof(int)*col);

	int ** arrLeft = (int **)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; ++i)
		arrLeft[i] = (int*)malloc(sizeof(int)*col);

	int ** arrRight = (int **)malloc(sizeof(int*)*row);
	for (int i = 0; i < row; ++i)
		arrRight[i] = (int*)malloc(sizeof(int)*col);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			arrUp[i][j] = arr[i][j];
			arrDown[i][j] = arr[i][j];
			arrLeft[i][j] = arr[i][j];
			arrRight[i][j] = arr[i][j];
		}
	}

	// They find how many moves are necessary for tiles to be placed to their correct positions.
	moveUp(arrUp,row,col);
	int closenessUp = findCloseness(arrUp,row,col);

	moveDown(arrDown,row,col);
	int closenessDown = findCloseness(arrDown,row,col);

	moveLeft(arrLeft,row,col);
	int closenessLeft = findCloseness(arrLeft,row,col);

	moveRight(arrRight,row,col);
	int closenessRight = findCloseness(arrRight,row,col);

	int * closenessArray = (int*)malloc(sizeof(int)*(4));
	closenessArray[0] = closenessUp;
	closenessArray[1] = closenessDown;
	closenessArray[2] = closenessLeft;
	closenessArray[3] = closenessRight;

	// To find which has the minimum moves.
	int cur_i,cur_j;
	findEmptyNode(arr,row,col,&cur_i,&cur_j);

	int min = pow(col,row)*col;
	for (int i = 0; i < 4; ++i)
	{
		if (closenessArray[i] < min)
		{
			// First it checks if there is an empty and suitable cell for the desired move. 
			if(i==0)
				if(checkValidty(arr,row,col,cur_i-1,cur_j) && arr[cur_i-1][cur_j] != 0)
					min = closenessArray[i];
			if(i==1)
				if(checkValidty(arr,row,col,cur_i+1,cur_j) && arr[cur_i+1][cur_j] != 0)
					min = closenessArray[i];
			if(i==2)
				if(checkValidty(arr,row,col,cur_i,cur_j-1) && arr[cur_i][cur_j-1] != 0)
					min = closenessArray[i];
			if(i==3)
				if(checkValidty(arr,row,col,cur_i,cur_j+1) && arr[cur_i][cur_j+1] != 0)
					min = closenessArray[i];
		}
	}


	if (min == closenessArray[0])
	{
		moveUp(arr,row,col);
		moveChoice = 'U';
	}

	else if (min == closenessArray[1])
	{
		moveDown(arr,row,col);
		moveChoice = 'D';
	}

	else if (min == closenessArray[2])
	{
		moveLeft(arr,row,col);
		moveChoice = 'L';
	}

	else if (min == closenessArray[3])
	{
		moveRight(arr,row,col);
		moveChoice = 'R';
	}

	for (int i = 0; i < row; ++i)
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


// This function is valid for HW1.
// It makes random moves to shuffle the puzzle.
void Shuffle(int ** arr,int size){

	// It takes the board to the final state.
	int curVal = 1;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{

			arr[i][j] = curVal;
			++curVal;
			
			if (i == size-1 && j== size-1)
			{
				arr[i][j] = -1;	
			}
					
		}
	}

	int cur_i,cur_j;
	int random;

	for (int i = 0; i < size*size; ++i)
	{
		random = rand() % 4 ; // there are four situation, so it does modular divison by 4.
		findEmptyNode(arr,size,size,&cur_i,&cur_j);

		// 0 represents move up situation.
		if (random == 0)
		{
			if (checkValidty(arr,size,size,cur_i-1,cur_j))	// It checks if there is an empty cell to move up.
				moveUp(arr,size);

			else
				--i;		// if there is not, it reduces the number of i to repeat the move.		
		}

		// 1 represents move down situation.
		if (random == 1)
		{
			if (checkValidty(arr,size,size,cur_i+1,cur_j))	// It checks if there is an empty cell to move down.
				moveDown(arr,size);

			else
				--i;	// if there is not, it reduces the number of i to repeat the move.
		}

		// 2 represents move right situation.
		if (random == 2)
		{
			if (checkValidty(arr,size,size,cur_i,cur_j+1))	// It checks if there is an empty cell to move right.
				moveRight(arr,size);

			else
				--i;	// if there is not, it reduces the number of i to repeat the move.
		}

		// 3 represents move left situation.
		if (random == 3)
		{
			if (checkValidty(arr,size,size,cur_i,cur_j-1))	// It checks if there is a empty cell to move left.
				moveLeft(arr,size);

			else
				--i;		// if there is not, it reduces the number of i to repeat the move.
		}
	}
}
  

// This function is valid for HW2.
// It makes random moves to shuffle the puzzle.
void Shuffle(int ** arr,int row, int col){

	// It takes the board to the final state.
	int curVal = 1;
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

	int cur_i,cur_j;
	int random;

	for (int i = 0; i < row*col; ++i)
	{
		random = rand() % 4 ; // there are four situation, so it does modular divison by 4.
		findEmptyNode(arr,row,col,&cur_i,&cur_j);

		// 0 represents move up situation.
		if (random == 0)
		{
			// It checks if there is an empty and a suitable cell to move up.
			if (checkValidty(arr,row,col,cur_i-1,cur_j) && arr[cur_i-1][cur_j] != 0)	
				moveUp(arr,row,col);

			// if there is not, it reduces the number of i to repeat the move.
			else
				--i; 		
		}

		// 1 represents move down situation.
		if (random == 1)
		{
			// It checks if there is an empty and a suitable cell to move down.
			if (checkValidty(arr,row,col,cur_i+1,cur_j) && arr[cur_i+1][cur_j] != 0)	
				moveDown(arr,row,col);

			// if there is not, it reduces the number of i to repeat the move.
			else
				--i;	
		}

		// 2 represents move right situation.
		if (random == 2)
		{
			// It checks if there is an empty and a suitable cell to move right.
			if (checkValidty(arr,row,col,cur_i,cur_j+1) && arr[cur_i][cur_j+1] != 0)	
				moveRight(arr,row,col);

			// if there is not, it reduces the number of i to repeat the move.
			else
				--i;	
		}

		// 3 represents move left situation.
		if (random == 3)
		{
			// It checks if there is an empty and a suitable cell to move left.
			if (checkValidty(arr,row,col,cur_i,cur_j-1) && arr[cur_i][cur_j-1] != 0)	
				moveLeft(arr,row,col);

			// if there is not, it reduces the number of i to repeat the move.
			else
				--i;		
		}
	}
}

// This functions is valid for both HW1 amd HW2.
// It quits the game.
inline void Exit(){

	cout<< "Game is terminated!" << endl;	
}


// This function is valid for both HW1 and HW2.
// It detects whether the intelligent move gets stucks.
// If ıt gets stuck it returns true.
bool getStuck(char * arrChoice, char intelligentMoveChoice, int currentSize){

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


// This function is valid for HW1.
// It is a helper function to be used in new Intelligent algorithm. 
// Blank tile moves randomly.
void moveRandom(int** arr, int size){

	int cur_i;
	int cur_j;
	int random;

	for (int i = 0; i < 1; ++i)
	{

		random = rand() % 4; // There are four situations.
		findEmptyNode(arr,size,size,&cur_i,&cur_j);

		if (random == 0)
		{
			// It checks if there is an empty and a suitable cell to move up.
			if (checkValidty(arr,size,size,cur_i-1,cur_j)){
				moveUp(arr,size);
			}

			// If it is not, it reduces the number of i to repeat the move.
			else
				--i;				
		}

		// 1 represents move down situation.
		if (random == 1)
		{
			// It checks if there is an empty and a suitable cell to move down.
			if (checkValidty(arr,size,size,cur_i+1,cur_j)){	
				moveDown(arr,size);
			}

			// If it is not, it reduces the number of i to repeat the move.
			else
				--i;
		}

		// 2 represents move right situation.
		if (random == 2)
		{
			// It checks if there is an empty and a suitable cell to move right.
			if (checkValidty(arr,size,size,cur_i,cur_j+1)){	
				moveRight(arr,size);	
			}

			// If it is not, it reduces the number of i to repeat the move.
			else
				--i;
		}

		// 3 represents move left situation.
		if (random == 3)
		{
			// It checks if there is an empty and a suitable cell to move left.
			if (checkValidty(arr,size,size,cur_i,cur_j-1)){	
				moveLeft(arr,size);		
			}

			// If it is not, it reduces the number of i to repeat the move.
			else
				--i;
		}
	}
}


// This function is valid for HW2.
// It is a helper function to be used in new Intelligent algorithm. 
// Blank tile moves randomly.
void moveRandom(int** arr, int row, int col){

	int cur_i;
	int cur_j;
	int random;

	for (int i = 0; i < 1; ++i)
	{

		random = rand() % 4; // There are four situations.
		findEmptyNode(arr,row,col,&cur_i,&cur_j);

		if (random == 0)
		{
			// It checks if there is an empty and a suitable cell to move up.
			if (checkValidty(arr,row,col,cur_i-1,cur_j) && arr[cur_i-1][cur_j] != 0){
				moveUp(arr,row,col);
			}

			// If it is not, it reduces the number of i to repeat the move.
			else
				--i;				
		}

		// 1 represents move down situation.
		if (random == 1)
		{
			// It checks if there is an empty and a suitable cell to move down.
			if (checkValidty(arr,row,col,cur_i+1,cur_j) && arr[cur_i+1][cur_j] != 0){	
				moveDown(arr,row,col);
			}

			// If it is not, it reduces the number of i to repeat the move.
			else
				--i;
		}

		// 2 represents move right situation.
		if (random == 2)
		{
			// It checks if there is an empty and a suitable cell to move right.
			if (checkValidty(arr,row,col,cur_i,cur_j+1) && arr[cur_i][cur_j+1] != 0){	
				moveRight(arr,row,col);	
			}

			// If it is not, it reduces the number of i to repeat the move.
			else
				--i;
		}

		// 3 represents move left situation.
		if (random == 3)
		{
			// It checks if there is an empty and a suitable cell to move left.
			if (checkValidty(arr,row,col,cur_i,cur_j-1) && arr[cur_i][cur_j-1] != 0){	
				moveLeft(arr,row,col);		
			}

			// If it is not, it reduces the number of i to repeat the move.
			else
				--i;
		}
	}
}


// This function is valid for both HW1 and HW2.
// It gets you to the solution.
int findSolution(int** arr, int row, int col, int fileFormat){

	int number = 0;				// To calculates how many moves have been done.
	char intelligentMoveChoice;
	int curSize = -1;			// Index of the move choices.
	char * arrChoice = (char*)malloc(sizeof(char)*(1000));

	if (fileFormat == 1)
	{	

		// Until the solution is found, make random moves and intelligent moves.
		while(!checkSolved(arr,row,col,fileFormat)){

			do{

				intelligentMoveChoice = IntelligentMove(arr,row);	// row and col are equal to each other.
				++ curSize;											// row represents size.
				++number;
				print2DMatrix(arr,row);
				cout<<endl;

			} while(getStuck(arrChoice, intelligentMoveChoice, curSize)!=true && checkSolved(arr,row,col,fileFormat)!=true);
			
			// Checked again if the game is solved, because if loop may end due to solved game,
			// It should not move again until the check point(other while loop)
			if (checkSolved(arr,row,col,fileFormat)!=true)
			{
				moveRandom(arr,row);
				print2DMatrix(arr,row);
				cout<<endl;
				++number;
			}

			if (checkSolved(arr,row,col,fileFormat)!=true)
			{
				moveRandom(arr,row);
				print2DMatrix(arr,row);
				cout<<endl;
				++number;
			}

			if (checkSolved(arr,row,col,fileFormat)!=true)
			{
				moveRandom(arr,row);
				print2DMatrix(arr,row);
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

	else 	// If file format is 2(HW2)
	{

		// Until the solution is found, make random moves and intelligent moves.
		while(!checkSolved(arr,row,col,fileFormat)){

			do{

				intelligentMoveChoice = IntelligentMove(arr,row,col);
				++ curSize;
				++number;
				print2DMatrix(arr,row,col);
				cout<<endl;

			} while(getStuck(arrChoice, intelligentMoveChoice, curSize)!=true && checkSolved(arr,row,col,fileFormat)!=true);
		

			// Checked again if the game is solved, because if loop ends due to solved game,
			// It should not move again until the check point(other while loop)
			if (checkSolved(arr,row,col,fileFormat)!=true)
			{
				moveRandom(arr,row,col);
				print2DMatrix(arr,row,col);
				cout<<endl;
				++number;
			}

			if (checkSolved(arr,row,col,fileFormat)!=true)
			{
				moveRandom(arr,row,col);
				print2DMatrix(arr,row,col);
				cout<<endl;
				++number;
			}

			if (checkSolved(arr,row,col,fileFormat)!=true)
			{
				moveRandom(arr,row,col);
				print2DMatrix(arr,row,col);
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


// This function is valid for both HW1 and HW2.
// It returns how many moves have been done.
void printReport(int *numberOfMoves, int move){

	*numberOfMoves += move; 
}


// This function is valid for HW1.
// It saves the current game board as a loadable file.
void saveGameBoard(int ** arr, int size){

	string fileName;

	cout << "Enter the file name" << endl;
	cin >> fileName;

	ofstream file;
	file.open(fileName);
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(arr[i][j] == -1) 	// -1 is blank tile.
				file <<"  ";

			else
				file << arr[i][j] << " ";
		}

		file << endl;
	}

	file.close();
}


// This function is valid for HW2.
// It saves the current game board as a loadable shape file.
void saveGameBoard(int ** arr, int row, int col){

	string fileName;

	cout << "Enter the file name" << endl;
	cin >> fileName;

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

// It checks shape file format. (HW1 format or HW2 format)
string checkFileFormat(int * result){

	*result = 1;

	string line;
	string wordd;
	const auto blankStr = "bb";
	string fileName;

	cout << "Enter the file name" << endl;
	cin >> fileName;

	ifstream file(fileName);

	if (file.is_open())
	{

		while (getline(file,line)){

			stringstream strStream(line);
			while( strStream >> wordd ){

				if (wordd.compare(blankStr) == 0) // If board has bb, then its format like in HW2.
					*result = 2;
			}
		}

		file.close();
	}

	else
		cout << "Unable to open file" << endl;

	return fileName;
}


// This function is valid for HW1.
// It loads the current game board from the file.
int ** loadGameBoard(string fileName, int *size){

	string line;
	string wordd;
	int ** str;

	ifstream file(fileName);
	if (file.is_open())
	{

		while (getline (file,line)) // To find size of game board.
        	++ *size;


		// number of the current size can be different from size of the shape file.
    	// So it allocates memory.
    	str = (int **)malloc(sizeof(int*)*(*size));	
		for (int i = 0; i < *size; ++i) 
			str[i] = (int*)malloc(sizeof(int)*(*size));


		char * strLine = (char*)malloc(sizeof(char)*(*size+(*size)+(*size))); 

		int i = 0; // row
		int j = 0; // col

		int count = 0;
		ifstream file2(fileName);
		string line2;

		while (getline(file2,line2)){

			line2.copy(strLine,line2.size()+1);	// It copies string to char array.
			strLine[line2.size()] = '\0';		


        	// Stringstream does not read blank tile.
        	// It reads strings by getLine function.
        	// and checks if each line contains more spaces than usual. 
			for (int k = 0; k < line2.size(); ++k)
      		{
        		if (k>0 && strLine[k] == strLine[k-1])
        		{	
        			if (strLine[k] == ' ')
        			{

        				// k is a index that shows string with spaces.
        				// So I find the normal index with no spaces.
        				for (int i = 0; i < k; ++i)
        				{
        					if (strLine[i] != ' ')	
        					{	
        						// This statement checks if the number is two-digits.
        						if (strLine[i+1] != ' '){
        							++count;
        							++i;
        						}

        						else	
        							++count;
        					}
        				}

        				str[i][count] = -1; 
        				k = line2.size(); // To finish loop
        			}
        										 
        		}

        		else{

        			if(k == 0 && strLine[k] == ' '){

        				str[i][k] = -1;	  // If k equals to zero, it equals to real index.
        				k = line2.size(); // If k equals to zero, for loop has to end. 
        				++j;			  // because it can enter first if statement.
        			}
        		}
        	}

			cout << line2 << endl;	// It prints shape file to the screen.

			stringstream strStream(line2);
			while( strStream >> wordd){

				if (str[i][j] != -1)
					str[i][j] = stoi(wordd);

				// If current array index represents blank tile, then index must be change.
				else{

					++j;
					str[i][j] = stoi(wordd);
				}

				++j;
			}

			j=0;
			++i;	
		}

		free(strLine);
		file.close();
	}

	else
		cout << "Unable to open file" << endl;

	return str;
}


// This function is valid for HW2.
// It loads the current game board from the file.
int ** loadGameBoard(string fileName, int * row, int * col){


	string line;
	string line2;
	string word;
	string wordd;
	const auto blankStr = "bb";
	int ** str;

	ifstream file(fileName);
	if (file.is_open())
	{

		while (getline (file,line)){ // To find number of rows
        	++ *row;

        	stringstream strStream(line);
        	while ( strStream >> word ) // To find number of columns
				++ *col;	
    	}

    	*col = *col / *row;

    	// number of the current row and column can be different from size of the shape file.
    	// So it allocates memory.
    	str = (int **)malloc(sizeof(int*)*(*row));	
		for (int i = 0; i < *row; ++i) 
			str[i] = (int*)malloc(sizeof(int)*(*col)); 

		int i = 0; // row
		int j = 0; // col

		ifstream file2(fileName);
		while (getline(file2,line2)){

			cout << line2 << endl;	// It prints shape file to the screen.

			stringstream strStream2(line2);
			while( strStream2 >> wordd){

				if (wordd.compare(blankStr) == 0)
					str[i][j] = -1;
					
				else
					str[i][j] = stoi(wordd);
				
				++j;
			}

			j=0;
			++i;	
		}

		file.close();
	}

	else
		cout << "Unable to open file" << endl;


	return str;
}


// This function is valid for HW1.
// It is a helper function to understand whether the game can be solved.
int getInversionNumber(int **arr, int size){


	int numberOfInversions = 0;
	int j = 0;
	int k = 0;

	int * array = (int*)malloc(sizeof(int)*(size*size));

	// It transforms 2-dimensional array into one-dimensional.
	for (int i = 0; i < (size*size); ++i)
	{
	 	if (arr[j][k] != -1)
	 	{
	 		array[i] = arr[j][k];
	 		++k;

	 		if (k == size )
	 		{
	 			k=0;
	 			++j;
	 		}
	 	}

	 	else{

	 		array[i] = -1;
	 		++k;

	 		if (k == size)
	 		{
	 			k=0;
	 			++j;
	 		}

	 	}

	} 

	// If array[i] > array[j] and i<j, there is a inversion.
	for (int i = 0; i < (size*size -1); ++i)
	{
		for (int j= i + 1; j < size*size; ++j)
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
// It is a helper function to understand whether the game can be solved.
// It finds where the blank tile is. It counts from bottom to top.
int findBlankPosition(int ** arr, int size){

	int row;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i][j] == -1)
			{
				row = size - i ; 
			}
		}
	}

	return row;
}


// This function is valid for HW1.
// It tests whether the game can be solved. 
// To understand that , it uses number of inversions and where the blank tile is.
const bool checkSolvable(int ** arr, int size){

	int numberOfInversions = getInversionNumber(arr,size);
	int blankPosition = findBlankPosition(arr,size);

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


// This function is valid for HW1.
void Menu(){

    // Row and col are necessary for HW2 format.
    // If user loads a game which has a format of HW2, while user was playing a game which has a format of HW1. 
	int row = 0;	
	int col = 0;
	int size ;

	char choice;
	char IntelligentMoveChoice;

	int numberOfMove = 0;
	int number; 			// this variable shows how many moves V command make.
	
	int fileFormat = 1;		// İnitial format. 1 represents HW1 format, 2 represents HW2 format.
	string fileName;

	do{
		cout << "Please enter the problem size" << endl;
		cin >> size;

		if (size!= 3 && size!=4 && size!=5 && size!=6 && size!=7 && size!=8 && size!=9)
		{
			cout << "Please enter a legal size (3x3,4x4,5x5,.....,9x9)" << endl;
		}

	} while (size !=3 && size != 4 && size != 5 && size != 6 && size != 7 && size != 8 && size !=9);


	srand(time(NULL));
	int ** arr;  


	do{

		arr = create2DMatrix(size);
		fillRandom(arr,size);

	} while(checkSolvable(arr,size) != true); 
	// if game is not solvable, create a random board until it is solvable.

	// Row and col will be used in checkSolved function.
	// İnitial file format is 1. So row and col are equal to each other.
	row = size;	
	col = size;

	cout << "Your initial random board is" << endl;
	print2DMatrix(arr,size);

	
	do{

		cout << "Your move : ";
		cin >> choice;

		if (choice == 'D' || choice == 'd')
		{
			if (fileFormat == 1 )
			{
				moveDown(arr,size);
				print2DMatrix(arr,size);
			}

			else{
				moveDown(arr,row,col);
				print2DMatrix(arr,row,col);
			}

			printReport(&numberOfMove,1);
		}

		else if (choice == 'U' || choice == 'u')
		{	

			if (fileFormat == 1){

				moveUp(arr,size);
				print2DMatrix(arr,size);
			}

			else{

				moveUp(arr,row,col);
				print2DMatrix(arr,row,col);
			}
			
			printReport(&numberOfMove,1);
		}	

		else if (choice == 'L' || choice == 'l')
		{
			if (fileFormat == 1)
			{
				moveLeft(arr,size);
				print2DMatrix(arr,size);
			}

			else
			{
				moveLeft(arr,row,col);
				print2DMatrix(arr,row,col);
			}
			
			printReport(&numberOfMove,1);
		}

		else if (choice == 'R' || choice == 'r')
		{

			if (fileFormat == 1)
			{
				moveRight(arr,size);
				print2DMatrix(arr,size);
			}
			
			else
			{
				moveRight(arr,row,col);
				print2DMatrix(arr,row,col);
			}

			printReport(&numberOfMove,1);
		}

		else if (choice == 'I' || choice == 'i')
		{

			if (fileFormat == 1)
			{
				IntelligentMoveChoice = IntelligentMove(arr,size);
				cout << "Intelligent move chooses " << IntelligentMoveChoice << endl;
				print2DMatrix(arr,size);
			}

			else
			{
				IntelligentMoveChoice = IntelligentMove(arr,row,col);
				cout << "Intelligent move chooses " << IntelligentMoveChoice << endl;
				print2DMatrix(arr,row,col);
			}
			
			printReport(&numberOfMove,1);
		}

		else if (choice == 'S' || choice == 's')
		{

			if (fileFormat == 1)
			{
				Shuffle(arr,size);
				print2DMatrix(arr,size);
			}

			else
			{
				Shuffle(arr,row,col);
				print2DMatrix(arr,row,col);
			}

			printReport(&numberOfMove,1);
		}

		else if (choice == 'V' || choice == 'v')
		{	
			if (fileFormat == 1)
				number = findSolution(arr,row,col,fileFormat);

			else
				number = findSolution(arr,row,col,fileFormat);
			
			printReport(&numberOfMove,number);			
		}

		else if (choice == 'E' || choice == 'e')
		{
			if (fileFormat == 1)
				saveGameBoard(arr,size);

			else
				saveGameBoard(arr,row,col);	
		}


		else if (choice == 'Y' || choice == 'y')
		{
			fileName = checkFileFormat(&fileFormat);

			if (fileFormat == 1){

				size = 0;
				arr = loadGameBoard(fileName,&size);
				row = size;
				col = size;
			}

			else{

				// it resets the number of row and col, because loadGameBoard updates this numbers.
				row = 0;	
				col = 0;
				arr = loadGameBoard(fileName,&row,&col);
			}
		}

		else if (choice == 'T' || choice == 't')
		{
			cout << "Total number of moves " << numberOfMove << endl;

			if (checkSolved(arr,row,col,fileFormat) != true)
				cout << "Solution is not found" << endl;

			else
				cout << "Solution is found" << endl;
		}

		else if (choice == 'Q' || choice == 'q')
		{
			Exit();
		}

		else
			cout << "Please enter legal moves (D, R, U, L, I, S, Q, V, T, E, Y)" << endl;


	} while(checkSolved(arr,row,col,fileFormat) != true && choice != 'Q' && choice != 'q');

	
	if (checkSolved(arr,row,col,fileFormat) == true){

		cout << "Problem solved!" << endl;
		cout << "Total number of moves " << numberOfMove <<endl;
	}

	for (int i = 0; i < row; ++i)
		free(arr[i]);
	free(arr);
}


// This function is valid for HW2.
void Menu(int ** arr, int row, int col, int fileFormat){

	int size;

	char choice;
	char IntelligentMoveChoice;

	int number;
	int numberOfMove = 0;

	//int fileFormat = 2;	// İnitial format is HW2. 
	string fileName;
	

	cout << "Your initial random board is" << endl;

	if (fileFormat == 2){
		print2DMatrix(arr,row,col);
	}

	else{
		print2DMatrix(arr,row);
		size = row;
	}

	
	do{
		cout << "Your move : ";
		cin >> choice;

		if (choice == 'D' || choice == 'd')
		{
			if (fileFormat == 1)
			{
				moveDown(arr,size);
				print2DMatrix(arr,size);
			}

			else
			{
				moveDown(arr,row,col);
				print2DMatrix(arr,row,col);
			}

			printReport(&numberOfMove,1);
		}

		else if (choice == 'U' || choice == 'u')
		{

			if (fileFormat == 1)
			{
				moveUp(arr,size);
				print2DMatrix(arr,size);
			}

			else
			{
				moveUp(arr,row,col);
				print2DMatrix(arr,row,col);
			}

			printReport(&numberOfMove,1);
		}	

		else if (choice == 'L' || choice == 'l')
		{

			if (fileFormat == 1)
			{
				moveLeft(arr,size);
				print2DMatrix(arr,size);	
			}

			else
			{
				moveLeft(arr,row,col);
				print2DMatrix(arr,row,col);
			}
			
			printReport(&numberOfMove,1);
		}

		else if (choice == 'R' || choice == 'r')
		{

			if (fileFormat == 1)
			{
				moveRight(arr,size);
				print2DMatrix(arr,size);
			}

			else
			{
				moveRight(arr,row,col);
				print2DMatrix(arr,row,col);
			}
			
			printReport(&numberOfMove,1);
		}

		else if (choice == 'I' || choice == 'i')
		{

			if (fileFormat == 1)
			{
				IntelligentMoveChoice = IntelligentMove(arr,size);
				cout << "Intelligent move chooses " << IntelligentMoveChoice << endl;
				print2DMatrix(arr,size);
			}

			else
			{
				IntelligentMoveChoice = IntelligentMove(arr,row,col);
				cout << "Intelligent move chooses " << IntelligentMoveChoice << endl;
				print2DMatrix(arr,row,col);
			}
			
			printReport(&numberOfMove,1);
		}

		else if (choice == 'S' || choice == 's')
		{

			if (fileFormat == 1)
			{
				Shuffle(arr,size);
				print2DMatrix(arr,size);
			}

			else
			{
				Shuffle(arr,row,col);
				print2DMatrix(arr,row,col);
			}
			
			printReport(&numberOfMove,1);
		}

		else if (choice == 'V' || choice == 'v')
		{
			if (fileFormat == 1)
				number = findSolution(arr,size,size,fileFormat);

			else
				number = findSolution(arr,row,col,fileFormat);	
			

			printReport(&numberOfMove,number);			
		}

		else if (choice == 'E' || choice == 'e')
		{
			if (fileFormat == 1)
				saveGameBoard(arr,size);

			else
				saveGameBoard(arr,row,col);
		}

		else if (choice == 'Y' || choice == 'y')
		{
			fileName = checkFileFormat(&fileFormat);

			if (fileFormat == 1){

				size = 0;
				arr = loadGameBoard(fileName,&size);
				row = size;
				col = size;
			}

			else{
				// it resets the number of row and col, because loadGameBoard updates this numbers.
				row = 0;
				col = 0;
				arr = loadGameBoard(fileName,&row,&col);
			}
		}

		else if (choice == 'T' || choice == 't')
		{
			cout << "Total number of moves " << numberOfMove << endl;

			if (checkSolved(arr,row,col,fileFormat) != true)
				cout << "Solution is not found" << endl;

			else
				cout << "Solution is found" << endl;
		}

		else if (choice == 'Q' || choice == 'q')
		{
			Exit();
		}

		else
			cout << "Please enter legal moves (D, R, U, L, I, S, V, T, E, Y, Q)" << endl;


		} while(checkSolved(arr,row,col,fileFormat) != true && choice != 'Q' && choice != 'q');


		if (checkSolved(arr,row,col,fileFormat) == true){

			cout << "Problem solved!" << endl;
			cout << "Total number of moves " << numberOfMove << endl;
		}

		for (int i = 0; i < row; ++i)
			free(arr[i]);
		free(arr);
}