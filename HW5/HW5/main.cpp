#include "BoardVector.h"
#include "BoardArray2D.h"
#include "BoardArray1D.h"

using namespace GtuGame;

namespace
{
	bool checkValidity(AbstractBoard* boards[], int size);
}

int main(int argc, char const *argv[])
{

		
	/**
	// Testing BoardVector class.
	// I use random 2D vector to make an object of BoardVector and test it.
	*/

	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  TESTİNG OF FUNCTIONS OF BOARDVECTOR CLASS                     " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;

	vector<vector<int>> v  = { {1,2,3},
							   {4,-1,6},
							   {8,5,7}		
						     };
	BoardVector boardVec(v);
	boardVec.set_game_format(2);
	cout << "Initial board" << endl;
	boardVec.print();
	cout << endl;

	/**
	// Testing of getRow function
	// Testing of getCol function
	*/
	cout << "Testing of getRow and getCol functions" << endl;
	cout << "Board has " << boardVec.getRow() << " rows and " << boardVec.getCol() << " cols" << endl; 

	/*  Testing of findEmptyNode function  */
	int _i;
	int _j;
	boardVec.findEmptyNode(_i,_j);
	cout << endl;
	cout << "Testing of findEmptyNode function" << endl;
	cout << "Position of blank tile is " << _i << ". row and " << _j << ". col" << endl;

	/**
	// Testing of move function
	// Testing of print function
	*/
	cout << endl;
	cout << "Testing move up" << endl;
	boardVec.move('U');
	boardVec.print();
	cout << endl;

	cout << "Testing move down" << endl;
	boardVec.move('D');
	boardVec.print();
	cout << endl;

	cout << "Testing move right" << endl;
	boardVec.move('R');
	boardVec.print();
	cout << endl;

	cout << "Testing move left" << endl;
	boardVec.move('L');
	boardVec.print();
	cout << endl;

	/*  Testing of numberOfMoves and lastMove functions  */
	cout << "Number of moves that this board made is " << boardVec.numberOfMoves() << endl;
	cout << "Last move of this board " << boardVec.lastMove() << endl;
	cout << endl;

	/*  Testing of operator ()  */
	cout << "Testing of operator ()" << endl;
	cout << "The element at the left-up corner is " << boardVec(0,0) << endl;
	cout << "The element at the middle is " << boardVec(1,1) << endl;
	cout << "The element at the right-down corner is " << boardVec(2,2) << endl;

	/*  Testing of reset function  */
	cout << endl;
	cout << "Testing reset function" << endl;
	boardVec.reset();
	boardVec.print();

	/*  Testing of isSolved function */
	cout << endl;
	cout << "Testing isSolved function" << endl;
	cout << "If board is a solution, then function should give us 1; if it is not, it should give us 0" << endl;
	cout << "Result is : " << boardVec.isSolved() << endl;

	/* Testing of readFromFile function, file name is TestingForBoardVectorReadFromFile.txt  */
	/* TestingForBoardVectorReadFromFile.txt file is in the folder because of that.  */
	cout << endl;
	cout << "Testing of readFromFile function" << endl;
	cout << "It reads a file which is TestingForBoardVectorReadFromFile.txt " << endl;
	cout << "You can change its content for testing" << endl;
	boardVec.readFromFile("TestingForBoardVectorReadFromFile.txt");

	/* Testing of writeToFile function, I give TestingForBoardVectorWriteToFile.txt as a file name. */
	/* This function will create a new file on the folder */
	cout << endl;
	boardVec.writeToFile("TestingForBoardVectorWriteToFile.txt");

	/*  Testing of operator ==	*/
	/*  Creating new object which is the initial value of boardVec  */
	cout << "Testing of operator ==" << endl;
	BoardVector boardVec2(v);
	cout << "First board is :" << endl;
	boardVec.print();
	cout << "Second board is:" << endl;
	boardVec2.print();
	if (boardVec == boardVec2)
		cout << "Boards are equal" << endl;
	else
		cout << "Boards are not equal" << endl;

	/**
	// Testing of setSize function.
	// By applying this function, now boardVec object has new size with junk values.
	*/
	cout << endl;
	cout << "Testing of setSize function" << endl;
	cout << "Board was resized" << endl;
	boardVec.setSize(4,5);
	cout << "Now, it has " << boardVec.getRow() << " rows and " << boardVec.getCol() << " cols" << endl; 
	cout << "It has junk values in it" << endl;



	/**************************************************************************************************/



	/**
	// Testing BoardArray2D class. 
	// I use readFromFile function to fill BoardArray2D object with values.
	*/
	cout << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  TESTİNG OF FUNCTIONS OF BOARDARRAY2D CLASS                    " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;

	BoardArray2D boardArray2D;
	boardArray2D.set_game_format(2);

	cout << "Testing of setSize function" << endl;
	cout << "Board was resized" << endl;
	boardArray2D.setSize(4,3);
	cout << "Now, it has " << boardArray2D.getRow() << " rows and " << boardArray2D.getCol() << " cols " 
		 << "but, it has junk values in it" << endl;

 	/* Testing of readFromFile function, file name is TestingForBoardArray2DReadFromFile.txt  */
	cout << endl;
	cout << "Testing of readFromFile function" << endl;
	cout << "It reads a file which is TestingForBoardArray2DReadFromFile.txt " << endl;
	cout << "You can change its content for testing" << endl;
	cout << "Initial board :" << endl;
	boardArray2D.readFromFile("TestingForBoardArray2DReadFromFile.txt");


	/*  Testing of Assignmet operator */
	/*  This object will be used in testing operator == later  */
	cout << endl;
	cout << "Testing of Assignmet operator" << endl;
	cout << "I assign boardArray2D object to new object called boardArray2D_2" << endl;
	cout << "Appearance of boardArray2D_2 object :" << endl;
	BoardArray2D boardArray2D_2 = boardArray2D;
	boardArray2D_2.print();

	/**
	// Testing of getRow function
	// Testing of getCol function
	*/
	cout << endl;
	cout << "Testing of getRow and getCol functions" << endl;
	cout << "Board has " << boardArray2D.getRow() << " rows and " << boardArray2D.getCol() << " cols" << endl; 

	/*  Testing of findEmptyNode function  */
	boardArray2D.findEmptyNode(_i,_j);
	cout << endl;
	cout << "Testing of findEmptyNode function" << endl;
	cout << "Position of blank tile is " << _i << ". row and " << _j << ". col" << endl;

	/**
	// Testing of move function
	// Testing of print function
	*/
	cout << endl;
	cout << "Testing move up" << endl;
	boardArray2D.move('U');
	boardArray2D.print();
	cout << endl;

	cout << "Testing move down" << endl;
	boardArray2D.move('D');
	boardArray2D.print();
	cout << endl;

	/*  Testing of numberOfMoves and lastMove functions  */
	cout << "Number of moves that this board made is " << boardArray2D.numberOfMoves() << endl;
	cout << "Last move of this board " << boardArray2D.lastMove() << endl;
	cout << endl;

	cout << "Testing move right" << endl;
	boardArray2D.move('R');
	boardArray2D.print();
	cout << endl;

	cout << "Testing move left" << endl;
	boardArray2D.move('L');
	boardArray2D.print();
	cout << endl;


	/*  Testing of isSolved function */
	cout << "Testing isSolved function" << endl;
	cout << "If board is a solution, then function should give us 1; if it is not, it should give us 0" << endl;
	cout << "Result is : " << boardArray2D.isSolved() << endl;

	/*  Testing of operator ()  */
	cout << endl;
	cout << "Testing of operator ()" << endl;
	cout << "Zeroth row and Second column has " << boardArray2D(0,2) << endl;
	cout << "Second row and fourth column has " << boardArray2D(2,4) << endl;
	cout << "First row and first column has  " << boardArray2D(1,1) << endl;

	/* Testing of writeToFile function, I give TestingForBoardArray2DWriteToFileFile.txt as a file name. */
	/* This function will create a new file on the folder */
	cout << endl;
	boardArray2D.writeToFile("TestingForBoardArray2DWriteToFile.txt");


	/*  Testing of operator ==	*/
	cout << "Testing of operator ==" << endl;
	cout << "First board is :" << endl;
	boardArray2D.print();
	cout << "Second board is:" << endl;
	boardArray2D_2.print();
	if (boardArray2D == boardArray2D_2)
		cout << "Boards are equal" << endl;
	else
		cout << "Boards are not equal" << endl;	

	/*  Testing of reset function  */
	cout << endl;
	cout << "Testing reset function" << endl;
	boardArray2D.reset();
	boardArray2D.print();


	/**************************************************************************************************/


	/**
	// Testing BoardArray1D class. 
	// I use random 1D array to make an object of BoardArray1D and test it.
	*/

	cout << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                  TESTİNG OF FUNCTIONS OF BOARDARRAY1D CLASS                    " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;

	int array[16] = {1,4,6,8,2,-1,11,12,3,10,5,7,9,13,14,15};

	/*  This board is represented with one-dimensional array  */ 
	/*  It actually looks like this:     
	1 4  6  8
	2    11 12
	3 10 5  7
	9 13 14 15
	*/

	BoardArray1D boardArray1D(4,4,array);
	boardArray1D.set_game_format(1);
	cout << "Initial board" << endl;
	boardArray1D.print();

	/*  Testing of Assignmet operator */
	/*  This object will be used in testing operator == later  */
	cout << endl;
	cout << "Testing of Assignmet operator" << endl;
	cout << "I assign boardArray1D object to new object called boardArray1D_2" << endl;
	cout << "Appearance of boardArray1D_2 object :" << endl;
	BoardArray1D boardArray1D_2 = boardArray1D;
	boardArray1D_2.print();

	/*  Testing of operator ==	*/
	cout << endl;
	cout << "Testing of operator ==" << endl;
	cout << "First board is :" << endl;
	boardArray1D.print();
	cout << "Second board is:" << endl;
	boardArray1D_2.print();
	if (boardArray1D == boardArray1D_2)
		cout << "Boards are equal" << endl;
	else
		cout << "Boards are not equal" << endl;

	/**
	// Testing of getRow function
	// Testing of getCol function
	*/
	cout << endl;
	cout << "Testing of getRow and getCol functions" << endl;
	cout << "Board has " << boardArray1D.getRow() << " rows and " << boardArray1D.getCol() << " cols" << endl; 

	/*  Testing of findEmptyNode function  */
	boardArray1D.findEmptyNode(_i,_j);
	cout << endl;
	cout << "Testing of findEmptyNode function" << endl;
	cout << "Position of blank tile is " << _i << ". row and " << _j << ". col" << endl;

	/**
	// Testing of move function
	// Testing of print function
	*/
	cout << endl;
	cout << "Testing move up" << endl;
	boardArray1D.move('U');
	boardArray1D.print();
	cout << endl;

	cout << "Testing move left" << endl;
	boardArray1D.move('L');
	boardArray1D.print();
	cout << endl;

	cout << "Testing move down" << endl;
	boardArray1D.move('D');
	boardArray1D.print();
	cout << endl;

	cout << "Testing move right" << endl;
	boardArray1D.move('R');
	boardArray1D.print();
	cout << endl;


	/*  Testing of numberOfMoves and lastMove functions  */
	cout << "Number of moves that this board made is " << boardArray1D.numberOfMoves() << endl;
	cout << "Last move of this board " << boardArray1D.lastMove() << endl;
	cout << endl;

	/*  Testing of isSolved function */
	cout << "Testing isSolved function" << endl;
	cout << "If board is a solution, then function should give us 1; if it is not, it should give us 0" << endl;
	cout << "Result is : " << boardArray1D.isSolved() << endl;

	/*  Testing of operator ()  */
	cout << endl;
	cout << "Testing of operator ()" << endl;
	cout << "Zeroth row and first column has " << boardArray1D(0,1) << endl;
	cout << "Second row and third column has " << boardArray1D(2,3) << endl;
	cout << "First row and second column has  " << boardArray1D(1,2) << endl;

	/* Testing of writeToFile function, I give TestingForBoardArray1DWriteToFileFile.txt as a file name. */
	/* This function will create a new file on the folder */
	cout << endl;
	boardArray1D.writeToFile("TestingForBoardArray1DWriteToFile.txt");
	

	/*  Testing of reset function  */
	cout << "Testing reset function" << endl;
	boardArray1D.reset();
	boardArray1D.print();

	/*  Testing of readFromFile function, file name is TestingForBoardArray1DReadFromFile.txt  */
	boardArray1D.set_game_format(2);
	cout << endl;
	cout << "Testing of readFromFile function" << endl;
	cout << "It reads a file which is TestingForBoardArray1DReadFromFile.txt " << endl;
	cout << "You can change its content for testing" << endl;
	cout << "Initial board :" << endl;
	boardArray1D.readFromFile("TestingForBoardArray1DReadFromFile.txt");

	/**
	// Testing of setSize function.
	// By applying this function, now boardArray1D object has new size with junk values.
	*/
	cout << endl;
	cout << "Testing of setSize function" << endl;
	cout << "Board was resized" << endl;
	boardArray1D.setSize(3,4);
	cout << "Now, it has " << boardArray1D.getRow() << " rows and " << boardArray1D.getCol() << " cols" << endl; 
	cout << "It has junk values in it" << endl;

	cout << endl;
	cout << "Total number of boards created so far :" << AbstractBoard::NumberOfBoards() << endl;
	/**************************************************************************************************/


	/*  Testing of global function.  */
	cout << endl;
	cout << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "                          TESTİNG OF GLOBAL FUNCTION                            " << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << endl;

	/*  PARAMETERS FOR  GLOBAL FUNCTION  */
	AbstractBoard* abstractBoard1[5];
	AbstractBoard* abstractBoard2[7];
	AbstractBoard* abstractBoard3[5];
	AbstractBoard* abstractBoard4[3];
	AbstractBoard* abstractBoard5[6];

/* ----------------------------------------------------------------------------------------------------*/

	/*  Create random BoardArray1D objects for testing */
	int arr1[9] = {1,4,6,8,2,-1,3,5,7};  
	int arr2[9] = {1,4,6,8,2,7,3,5,-1};  
	int arr3[9] = {1,4,6,8,2,7,3,-1,5};  
	int arr4[9] = {1,-1,6,8,2,7,3,4,5};
	int arr5[9] = {-1,1,6,8,2,7,3,4,5};
 
	/*  This sequence is wrong  */
	BoardArray1D boardArray1D1(3,3,arr1); 	// Initial board
	boardArray1D1.set_game_format(1);
	BoardArray1D boardArray1D2(3,3,arr2);	// Down version
	boardArray1D2.set_game_format(1);
	BoardArray1D boardArray1D3(3,3,arr3);	// Left version
	boardArray1D3.set_game_format(1);
	BoardArray1D boardArray1D4(3,3,arr4);	// Illegal move
	boardArray1D4.set_game_format(1);
	BoardArray1D boardArray1D5(3,3,arr5);	// Left version
	boardArray1D5.set_game_format(1);

	abstractBoard1[0] = &boardArray1D1;
	abstractBoard1[1] = &boardArray1D2;
	abstractBoard1[2] = &boardArray1D3;
	abstractBoard1[3] = &boardArray1D4;
	abstractBoard1[4] = &boardArray1D5;

	/*  Testing of first parameter abstractBoard1  */
	/*  This array of pointers, point to a wrong sequence of moves  */

	cout << "************* TEST - 1 **************" << endl;
	cout << "Sequence of boards :" << endl;
	boardArray1D1.print();     
	cout << "Down version" << endl;       
	boardArray1D2.print(); 
	cout << "Left version" << endl;
	boardArray1D3.print();
	cout << "Illegal move" << endl;
	boardArray1D4.print();
	cout << "Left version of Illegal move" << endl;
	boardArray1D5.print();

	cout << "This test includes a wrong sequence of moves, it should give us 0" << endl;
	cout << "Result: "<<checkValidity(abstractBoard1,5) << endl;

/* ----------------------------------------------------------------------------------------------------*/


	/*  Create a random BoardVector object for testing  */
	vector<vector<int>> v1  = {{1,3,5},
							   {8,-1,2},
							   {4,6,7}		
						      };
	vector<vector<int>> v2  = {{1,-1,5},
							   {8,3,2},
							   {4,6,7}		
						      };
	vector<vector<int>> v3  = {{-1,1,5},
							   {8,3,2},
							   {4,6,7}		
						      };
	vector<vector<int>> v4  = {{8,1,5},
							   {-1,3,2},
							   {4,6,7}		
						      };
	vector<vector<int>> v5  = {{8,1,5},
							   {3,-1,2},
							   {4,6,7}		
						      };
	vector<vector<int>> v6  = {{8,1,5},
							   {3,2,-1},
							   {4,6,7}		
						      };
	vector<vector<int>> v7  = {{8,1,5},
							   {3,2,7},
							   {4,6,-1}		
						      };
	/*  Sequence is correct  */ 
	BoardVector boardVector1(v1);
	boardVector1.set_game_format(1);
	BoardVector boardVector2(v2); 
	boardVector2.set_game_format(1);
	BoardVector boardVector3(v3); 
	boardVector3.set_game_format(1);
	BoardVector boardVector4(v4); 
	boardVector4.set_game_format(1);
	BoardVector boardVector5(v5); 
	boardVector5.set_game_format(1);
	BoardVector boardVector6(v6); 	
	boardVector6.set_game_format(1);
	BoardVector boardVector7(v7); 
	boardVector7.set_game_format(1);

	abstractBoard2[0] = &boardVector1;
	abstractBoard2[1] = &boardVector2;
	abstractBoard2[2] = &boardVector3;
	abstractBoard2[3] = &boardVector4;
	abstractBoard2[4] = &boardVector5;
	abstractBoard2[5] = &boardVector6;
	abstractBoard2[6] = &boardVector7;


	/*  Testing of second parameter abstractBoard2  */
	/*  This array of pointers, point to a correct sequence of moves  */
	cout << endl;
	cout << endl;
	cout << "************* TEST - 2 **************" << endl;
	cout << "Sequence of boards : " << endl;
	boardVector1.print();
	cout << "Up version " << endl;
	boardVector2.print(); 
	cout << "Left version " << endl;
	boardVector3.print();
	cout << "Down version " << endl;
	boardVector4.print();
	cout << "Right version " << endl;
	boardVector5.print();
	cout << "Right version " << endl;
	boardVector6.print();
	cout << "Down version" << endl;
	boardVector7.print();

	cout << "This test includes a correct sequence of moves, it should give us 1" << endl;
	cout << "Result: ";
	cout << checkValidity(abstractBoard2,7)<< endl;

/* ----------------------------------------------------------------------------------------------------*/


	/*  abstractBoard3 array of pointers, points both BoardVector and BoardArray1D objects.  */ 
	int arr6[9] = {8,1,5,-1,3,2,4,6,7};
	int arr7[9] = {8,1,5,3,-1,2,4,6,7};
	BoardArray1D boardArray1D6(3,3,arr6); 	
	boardArray1D6.set_game_format(1);
	BoardArray1D boardArray1D7(3,3,arr7);	
	boardArray1D7.set_game_format(1);

	abstractBoard3[0] = &boardVector1;
	abstractBoard3[1] = &boardVector2;
	abstractBoard3[2] = &boardVector3;
	abstractBoard3[3] = &boardArray1D6;
	abstractBoard3[4] = &boardArray1D7;


	/*  Testing of third parameter abstractBoard3  */
	/*  This array of pointers, point to a correct sequence of moves  */
	cout << endl;
	cout << endl;
	cout << "************* TEST - 3 **************" << endl;
	cout << "Sequence of boards : " << endl;
	boardVector1.print();
	cout << "Up version " << endl;
	boardVector2.print(); 
	cout << "Left version " << endl;
	boardVector3.print();
	cout << "Down version " << endl;
	boardArray1D6.print();
	cout << "Right version " << endl;
	boardArray1D7.print();

	cout << "This test includes a correct sequence of moves, it should give us 1" << endl;
	cout << "Result: ";
	cout << checkValidity(abstractBoard3,5)<< endl;

/* ----------------------------------------------------------------------------------------------------*/


	/*  Create a random BoardArray2D objects for testing  */
	int Array1[3][4] = {{1,0,9,0},
					   {5,6,8,3},
					   {2,-1,7,4}
					   };
    int** arrr1 = new int*[3];
	for (int i = 0; i < 3; ++i)
		arrr1[i] = new int[4];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			arrr1[i][j] = Array1[i][j];

	int Array2[3][4] = {{1,0,9,0},
					   {5,-1,8,3},
					   {2,6,7,4}
					  };
	int** arrr2 = new int*[3];
	for (int i = 0; i < 3; ++i)
		arrr2[i] = new int[4];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			arrr2[i][j] = Array2[i][j];

	int Array3[3][4] = {{1,-1,9,0},
					   {5,0,8,3},
					   {2,6,7,4}
					  };
	int** arrr3 = new int*[3];
	for (int i = 0; i < 3; ++i)
		arrr3[i] = new int[4];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			arrr3[i][j] = Array3[i][j];

	BoardArray2D boardArray2D1(3,4,arrr1);	 // Initial board
	boardArray2D1.set_game_format(2);
	BoardArray2D boardArray2D2(3,4,arrr2);	 // Up version
	boardArray2D2.set_game_format(2);
	BoardArray2D boardArray2D3(3,4,arrr3);  // Illegal move, it moves up, but upper tile was imposible tile.
	boardArray2D3.set_game_format(2);

	abstractBoard4[0] = &boardArray2D1;
	abstractBoard4[1] = &boardArray2D2;
	abstractBoard4[2] = &boardArray2D3;

	/*  Testing of fourth parameter abstractBoard4  */
	/*  This array of pointers, point to a wrong sequence of moves  */
	cout << endl;
	cout << endl;
	cout << "************* TEST - 4 **************" << endl;
	cout << "Sequence of boards : " << endl;
	boardArray2D1.print();
	cout << "Up version " << endl;
	boardArray2D2.print(); 
	cout << "Illegal move " << endl;
	boardArray2D3.print();

	cout << "This test includes a wrong sequence of moves, it should give us 0" << endl;
	cout << "Result: ";
	cout << checkValidity(abstractBoard4,3)<< endl;

/* ----------------------------------------------------------------------------------------------------*/

	/*  abstractBoard5 array of pointers, points both BoardVector and BoardArray2D objects.  */ 
	vector<vector<int>> vector1  = {{1,0,9,0},
							        {-1,5,8,3},
							        {2,6,7,4}		
						           };

	vector<vector<int>> vector2  = {{1,0,9,0},
							        {5,-1,8,3},
							        {2,6,7,4}		
						           };

	vector<vector<int>> vector3  = {{1,0,9,0},
							        {5,8,-1,3},
							        {2,6,7,4}
							    	};

	vector<vector<int>> vector4  = {{1,0,9,0},
							        {5,8,2,3},
							        {-1,6,7,4}
							    	};						    	

	BoardVector board_Vec1(vector1);
	board_Vec1.set_game_format(2);
	BoardVector board_Vec2(vector2); 
	board_Vec2.set_game_format(2);
	BoardVector board_Vec3(vector3); 
	board_Vec3.set_game_format(2);
	BoardVector board_Vec4(vector4); 
	board_Vec4.set_game_format(2);

	abstractBoard5[0] = &boardArray2D1;
	abstractBoard5[1] = &boardArray2D2;
	abstractBoard5[2] = &board_Vec1;
	abstractBoard5[3] = &board_Vec2;
	abstractBoard5[4] = &board_Vec3;
	abstractBoard5[5] = &board_Vec4;

	/*  Testing of fifth parameter abstractBoard5  */
	/*  This array of pointers, point to a wrong sequence of moves  */
	cout << endl;
	cout << endl;
	cout << "************* TEST - 5 **************" << endl;
	cout << "Sequence of boards : " << endl;
	boardArray2D1.print();
	cout << "Up version " << endl;
	boardArray2D2.print(); 
	cout << "Left version " << endl;
	board_Vec1.print();
	cout << "Right version " << endl;
	board_Vec2.print();
	cout << "Right version " << endl;
	board_Vec3.print();
	cout << "Illegal move " << endl;
	board_Vec4.print();

	cout << "This test includes a wrong sequence of moves, it should give us 0" << endl;
	cout << "Result: ";
	cout << checkValidity(abstractBoard5,6)<< endl;
	
/* ----------------------------------------------------------------------------------------------------*/
	

	for (int i = 0; i < 3; ++i)
		delete [] arrr1[i];
	delete [] arrr1;

	for (int i = 0; i < 3; ++i)
		delete [] arrr2[i];
	delete [] arrr2;

	for (int i = 0; i < 3; ++i)
		delete [] arrr3[i];
	delete [] arrr3;


	return 0;
}



namespace
{
	bool checkValidity(AbstractBoard* boards[], int size)
	{	

 		int cur_i;
 		int cur_j;
 		int next_cur_i;
 		int next_cur_j;

 		int value;
 		int i_distance;
 		int j_distance;

 		/* Cast the current and the next element to understand what type of an object it points*/
 		for (int i = 0; i < size-1; ++i)
 		{
 			BoardVector*  boardVectorPtr  = dynamic_cast<BoardVector*>  (boards[i]);
			BoardArray2D* boardArray2DPtr = dynamic_cast<BoardArray2D*> (boards[i]);
			BoardArray1D* boardArray1DPtr = dynamic_cast<BoardArray1D*> (boards[i]);

			BoardVector*  boardVectorPtr2  = dynamic_cast<BoardVector*>  (boards[i+1]);
			BoardArray2D* boardArray2DPtr2 = dynamic_cast<BoardArray2D*> (boards[i+1]);
			BoardArray1D* boardArray1DPtr2 = dynamic_cast<BoardArray1D*> (boards[i+1]);

			// Find the positions of the blank tile of the current node.
			if (boardVectorPtr != nullptr)
				boardVectorPtr->findEmptyNode(cur_i,cur_j);
			
			if (boardArray2DPtr != nullptr)
				boardArray2DPtr->findEmptyNode(cur_i,cur_j);

			if (boardArray1DPtr != nullptr)
				boardArray1DPtr->findEmptyNode(cur_i,cur_j);
			
			// Find the positions of the blank tile of the next node.
			if (boardVectorPtr2 != nullptr)
				boardVectorPtr2->findEmptyNode(next_cur_i,next_cur_j);

			if (boardArray2DPtr2 != nullptr)
				boardArray2DPtr2->findEmptyNode(next_cur_i,next_cur_j);

			if (boardArray1DPtr2 != nullptr)
				boardArray1DPtr2->findEmptyNode(next_cur_i,next_cur_j);
				
			// This three if statements are needed for understanding if blank tile switches place with imposible tile.
			if (boardVectorPtr != nullptr)
				value = boardVectorPtr->operator()(next_cur_i,next_cur_j);
			
			if (boardArray2DPtr != nullptr)
				value = boardArray2DPtr->operator()(next_cur_i,next_cur_j);

			if (boardArray1DPtr != nullptr)
				value = boardArray1DPtr->operator()(next_cur_i,next_cur_j);
			
			// find the distance  between
			// position of blank tile of current element and position of blank tile of next element
			i_distance = abs(cur_i - next_cur_i);
 			j_distance = abs(cur_j - next_cur_j);
 			// If one of the axis is bigger than one
 			// or it switches place with imposibble tile, return false .
 			if (i_distance == 1 && j_distance == 0){
 				if (value == 0){
 					return false;
 				}
 			}


 			else if (i_distance == 0 && j_distance == 1){
 				if (value == 0){
 					return false;
 				}
 			}
	
 			else if (i_distance == 0 && j_distance == 0){
 				if (value == 0){
 					return false;
 				}
 			}

 			else
 				return false;
 		}

		return true;
	}
}