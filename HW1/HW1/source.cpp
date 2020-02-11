#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "source.h"

using namespace std;

// This function tests whether the problem is solved. 
// If it equals to the final solution, it returns true.
bool checkSolved(int ** arr,int size)
{	
	int curVal = 1;
	for (int i = 0; i < size; ++i){
		if(i==size-1) // -1 represents blank tile. I reduce size, because last tile has to be blank. 
			size--;
		for (int j = 0; j < size; ++j)
			if(arr[i][j]!=curVal++)
				return false;	
	}
	return true;
}

// It finds the location of blank tile.
void findEmptyNode(int **arr, int size, int * cur_i, int *cur_j){
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(arr[i][j]==-1){
				*cur_i = i;
				*cur_j = j;
				return;
			}
		}
	}
}

int ** create2DMatrix(int size)
{
	int ** arr = (int **)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; ++i) // row
		arr[i] = (int*)malloc(sizeof(int)*size); // column
	return arr;
}

// It is a helper function to be used in other functions. 
// It will be used to check if there is an empty cell for the current movement.
bool checkValidty(int ** arr, int size, int i,int j){
	return (i<size && i>=0 && j<size && j>=0);
}

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
				return;	// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
			}
		}
	}
}

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
				return; // The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
			}
			
		}
	}
}

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

// It makes an intelligent move for you. This means after the move, all the tiles are closer to their final positions.
char IntelligentMove(int ** arr,int size){


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
	findEmptyNode(arr,size,&cur_i,&cur_j);
	int min = size*size*size;
	for (int i = 0; i < 4; ++i)
	{
		if (closenessArray[i] < min)
		{
			// First it checks if there is an empty cell for the desired move. 
			if(i==0)
				if(checkValidty(arr,size,cur_i-1,cur_j))
					min = closenessArray[i];
			if(i==1)
				if(checkValidty(arr,size,cur_i+1,cur_j))
					min = closenessArray[i];
			if(i==2)
				if(checkValidty(arr,size,cur_i,cur_j-1))
					min = closenessArray[i];
			if(i==3)
				if(checkValidty(arr,size,cur_i,cur_j+1))
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
		findEmptyNode(arr,size,&cur_i,&cur_j);

		// 0 represents move up situation.
		if (random == 0)
		{
			if (checkValidty(arr,size,cur_i-1,cur_j))	// It checks if there is a empty cell to move up.
				moveUp(arr,size);

			else
				--i;		// if there is not, it reduces the number of i to repeat the move.		
		}


		// 1 represents move down situation.
		if (random == 1)
		{
			if (checkValidty(arr,size,cur_i+1,cur_j))	// It checks if there is a empty cell to move down.
				moveDown(arr,size);

			else
				--i;	// if there is not, it reduces the number of i to repeat the move.
		}


		// 2 represents move right situation.
		if (random == 2)
		{
			if (checkValidty(arr,size,cur_i,cur_j+1))	// It checks if there is a empty cell to move right.
				moveRight(arr,size);

			else
				--i;	// if there is not, it reduces the number of i to repeat the move.
		}


		// 3 represents move left situation.
		if (random == 3)
		{
			if (checkValidty(arr,size,cur_i,cur_j-1))	// It checks if there is a empty cell to move left.
				moveLeft(arr,size);

			else
				--i;		// if there is not, it reduces the number of i to repeat the move.
		}


	}
}

// It quits the game.
void Exit(){

	cout<< "Game is terminated!" << endl;	
}

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

// It tests whether the game can be solved. 
// To understand that , it uses number of inversions and where the blank tile is.
bool checkSolvable(int ** arr, int size){

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

void Menu(){


	int size ;
	char choice;
	char IntelligentMoveChoice;
	int numberOfMove = 0;

	do{
		cout << "Please enter the problem size" << endl;
		cin >> size;

		if (size<3 || size>9)
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


	cout << "Your initial random board is" << endl;
	print2DMatrix(arr,size);

	
	do{

		cout << "Your move : ";
		cin >> choice;

		if (choice == 'D' || choice == 'd')
		{
			moveDown(arr,size);
			print2DMatrix(arr,size);
			++numberOfMove;
		}

		else if (choice == 'U' || choice == 'u')
		{
			moveUp(arr,size);
			print2DMatrix(arr,size);
			++numberOfMove;
		}	

		else if (choice == 'L' || choice == 'l')
		{
			moveLeft(arr,size);
			print2DMatrix(arr,size);
			++numberOfMove;
		}

		else if (choice == 'R' || choice == 'r')
		{
			moveRight(arr,size);
			print2DMatrix(arr,size);
			++numberOfMove;
		}

		else if (choice == 'I' || choice == 'i')
		{
			IntelligentMoveChoice = IntelligentMove(arr,size);
			cout << "Intelligent move chooses " << IntelligentMoveChoice << endl;
			print2DMatrix(arr,size);
			++numberOfMove;
		}

		else if (choice == 'S' || choice == 's')
		{
			Shuffle(arr,size);
			print2DMatrix(arr,size);
			++numberOfMove;
		}

		else if (choice == 'Q' || choice == 'q')
		{
			Exit();
		}

		else
			cout << "Please enter legal moves (D, R, U, L, I, S, Q)" << endl;


	} while(checkSolved(arr,size) != true && choice != 'Q');

	
	if (checkSolved(arr,size) == true){

		cout << "Problem solved!" << endl;
		cout << "Total number of moves " << numberOfMove <<endl;
	}

	for (int i = 0; i < size; ++i)
		free(arr[i]);
	free(arr);

}