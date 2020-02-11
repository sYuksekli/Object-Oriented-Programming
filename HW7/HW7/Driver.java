import java.util.Vector;

public class Driver
{

	public static void main(String[] args) {

	try
	{

	/**
	// Testing BoardArray2D class. 
	// I use readFromFile function to fill BoardArray2D object with values.
	*/
	System.out.println();
	System.out.println();
	System.out.println("--------------------------------------------------------------------------------");
	System.out.println("                  TESTİNG OF FUNCTIONS OF BOARDARRAY2D CLASS                    ");
	System.out.println("--------------------------------------------------------------------------------");
	System.out.println();

	BoardArray2D boardArray2D = new BoardArray2D();
	boardArray2D.set_game_format(2);

	System.out.println("Testing of setSize,getRow and getCol functions"); 
	System.out.println("Board was resized"); 
	boardArray2D.setSize(4,3);
	System.out.println("Now, it has " +boardArray2D.getRow() +" rows and "+ boardArray2D.getCol() +" cols " 
		 + "but, it has junk values in it"); 

 	/* Testing of readFromFile function, file name is TestingForBoardArray2DReadFromFile.txt  */
	System.out.println(); 
	System.out.println("Testing of readFromFile function"); 
	System.out.println("It reads a file which is TestingForBoardArray2DReadFromFile.txt "); 
	System.out.println("You can change its content for testing"); 
	System.out.println("Initial board :");
	boardArray2D.readFromFile("TestingForBoardArray2DReadFromFile.txt");
	System.out.println();

	
	/**
	// Testing of move function
	// Testing of toString function
	*/
	System.out.println();
	System.out.println("Testing move up"); 
	boardArray2D.move('U');
	System.out.println(boardArray2D);
	System.out.println(); 

	System.out.println("Testing move down"); 
	boardArray2D.move('D');
	System.out.println(boardArray2D);
	System.out.println(); 

	/*  Testing of numberOfMoves and lastMove functions  */
	System.out.println("Testing of numberOfMoves and lastMove functions"); 
	System.out.println("Number of moves that this board made is "+ boardArray2D.numberOfMoves()); 
	System.out.println("Last move of this board "+ boardArray2D.lastMove());
	System.out.println(); 

	System.out.println("Testing move right"); 
	boardArray2D.move('R');
	System.out.println(boardArray2D);
	System.out.println(); 

	System.out.println("Testing move left");
	boardArray2D.move('L');
	System.out.println(boardArray2D);
	System.out.println(); 


	/*  Testing of isSolved function */
	System.out.println("Testing isSolved function");
	System.out.println("If board is a solution, then function should give us true; if it is not, it should give us false"); 
	System.out.println("Result is : "+ boardArray2D.isSolved());

	/*  Testing of cell function  */
	System.out.println();
	System.out.println("Testing of cell function"); 
	System.out.println("Zeroth row and Second column has "+ boardArray2D.cell(0,2));
	System.out.println("Second row and fourth column has "+ boardArray2D.cell(2,4));
	System.out.println("First row and first column has "+ boardArray2D.cell(1,1)); 

	/* Testing of writeToFile function, I give TestingForBoardArray2DWriteToFile.txt as a file name. */
	/* This function will create a new file on the folder */
	System.out.println();
	boardArray2D.writeToFile("TestingForBoardArray2DWriteToFile.txt");


	/*  Testing of Equals function	*/
	int [][] arrayForEquality = {
								  {1,3,8},
								  {0,-1,7},
								  {2,4,5}
								  };

	BoardArray2D boardArray2D_2 = new BoardArray2D(3,3,arrayForEquality);
	boardArray2D_2.set_game_format(2);
	System.out.println("I create new boardArray2D object called boardArray2D_2"); 

	System.out.println("Testing of Equals function"); 
	System.out.println("First board is :"); 
	System.out.println(boardArray2D);
	System.out.println("Second board is :"); 
	System.out.println(boardArray2D_2);
	if (boardArray2D.Equals(boardArray2D_2))
		System.out.println("Boards are equal"); 
	else
		System.out.println("Boards are not equal"); 	

	/*  Testing of reset function  */
	System.out.println(); 
	System.out.println("Testing reset function"); 
	boardArray2D.reset();
	System.out.println(boardArray2D);


	/**************************************************************************************************/


	/**
	// Testing BoardArray1D class. 
	// I use random 1D array to make an object of BoardArray1D and test it.
	*/

	System.out.println();
	System.out.println();
	System.out.println("--------------------------------------------------------------------------------");
	System.out.println("                  TESTİNG OF FUNCTIONS OF BOARDARRAY1D CLASS                    ");
	System.out.println("--------------------------------------------------------------------------------");
	System.out.println();

	int [] array = {1,4,6,8,2,-1,11,12,3,10,5,7,9,13,14,15};

	/*  This board is represented with one-dimensional array  */ 
	/*  It actually looks like this:     
	1 4  6  8
	2    11 12
	3 10 5  7
	9 13 14 15
	*/

	BoardArray1D boardArray1D = new BoardArray1D(4,4,array);
	boardArray1D.set_game_format(1);
	System.out.println("Initial board");
	System.out.println(boardArray1D);
	System.out.println();

	BoardArray1D boardArray1D_2 = new BoardArray1D(4,4,array);
	boardArray1D_2.set_game_format(1);
	System.out.println("I create boardArray1D object called boardArray1D_2 for testing Equals function");

	/*  Testing of  Equals function	*/
	System.out.println();
	System.out.println("Testing of Equals function");
	System.out.println("First board is :");
	System.out.println(boardArray1D);
	System.out.println("Second board is:");
	System.out.println(boardArray1D_2);

	if (boardArray1D.Equals(boardArray1D_2))
		System.out.println("Boards are equal");
	else
		System.out.println("Boards are not equal");

	
	/**
	// Testing of move function
	// Testing of toString function
	*/
	System.out.println();
	System.out.println("Testing move up");
	boardArray1D.move('U');
	System.out.println(boardArray1D);
	System.out.println();

	System.out.println("Testing move left");
	boardArray1D.move('L');
	System.out.println(boardArray1D);
	System.out.println();

	System.out.println("Testing move down");
	boardArray1D.move('D');
	System.out.println(boardArray1D);
	System.out.println();

	System.out.println("Testing move right");
	boardArray1D.move('R');
	System.out.println(boardArray1D);
	System.out.println();


	/*  Testing of numberOfMoves and lastMove functions  */
	System.out.println("Testing of numberOfMoves and lastMove functions");
	System.out.println("Number of moves that this board made is "+ boardArray1D.numberOfMoves());
	System.out.println("Last move of this board "+ boardArray1D.lastMove());
	System.out.println();

	/*  Testing of isSolved function */
	System.out.println("Testing isSolved function");
	System.out.println("If board is a solution, then function should give us true; if it is not, it should give us false");
	System.out.println("Result is : " + boardArray1D.isSolved());

	/*  Testing of cell function  */
	System.out.println();
	System.out.println("Testing of cell function");
	System.out.println("Zeroth row and first column has " + boardArray1D.cell(0,1));
	System.out.println("Second row and third column has " + boardArray1D.cell(2,3));
	System.out.println("First row and second column has " + boardArray1D.cell(1,2));

	/* Testing of writeToFile function, I give TestingForBoardArray1DWriteToFile.txt as a file name. */
	/* This function will create a new file on the folder */
	System.out.println();
	boardArray1D.writeToFile("TestingForBoardArray1DWriteToFile.txt");
	

	/*  Testing of reset function  */
	System.out.println("Testing reset function");
	boardArray1D.reset();
	System.out.println(boardArray1D);

	/*  Testing of readFromFile function, file name is TestingForBoardArray1DReadFromFile.txt  */
	boardArray1D.set_game_format(2);
	System.out.println();
	System.out.println("Testing of readFromFile function");
	System.out.println("It reads a file which is TestingForBoardArray1DReadFromFile.txt");
	System.out.println("You can change its content for testing");
	System.out.println("Initial board :");
	boardArray1D.readFromFile("TestingForBoardArray1DReadFromFile.txt");

	/**
	// Testing of setSize function.
	// By applying this function, now boardArray1D object has new size with junk values.
	*/
	System.out.println();
	System.out.println("Testing of setSize,getRow and getCol functions");
	System.out.println("Board was resized");
	boardArray1D.setSize(3,4);
	System.out.println("Now, it has "+ boardArray1D.getRow() +" rows and "+ boardArray1D.getCol() +" cols"); 
	System.out.println("It has junk values in it");

	/* Testing of NumberOfBoards function */
	System.out.println();
	System.out.println("Total number of boards created so far :" + AbstractBoard.NumberOfBoards());
	/**************************************************************************************************/


	/*  Testing of static CheckValidity function.  */
	System.out.println();
	System.out.println();
	System.out.println("--------------------------------------------------------------------------------");
	System.out.println("            TESTİNG OF STATIC CHECKVALIDITY FUNCTION                            ");
	System.out.println("--------------------------------------------------------------------------------");
	System.out.println();


	/*  PARAMETERS FOR  STATIC CHECKVALIDITY FUNCTION  */
	AbstractBoard [] abstractBoard1 = new AbstractBoard[5];
	AbstractBoard [] abstractBoard2 = new AbstractBoard[7];
	AbstractBoard [] abstractBoard3 = new AbstractBoard[5];
	AbstractBoard [] abstractBoard4 = new AbstractBoard[3];
	AbstractBoard [] abstractBoard5 = new AbstractBoard[6];

/* ----------------------------------------------------------------------------------------------------*/

	/*  Create random BoardArray1D objects for testing */
	int [] arr1 = {1,4,6,8,2,-1,3,5,7};  
	int [] arr2 = {1,4,6,8,2,7,3,5,-1};  
	int [] arr3 = {1,4,6,8,2,7,3,-1,5};  
	int [] arr4 = {1,-1,6,8,2,7,3,4,5};
	int [] arr5 = {-1,1,6,8,2,7,3,4,5};
 
	/*  This sequence is wrong  */
	BoardArray1D boardArray1D1 = new BoardArray1D(3,3,arr1); 	// Initial board
	boardArray1D1.set_game_format(1);
	BoardArray1D boardArray1D2 = new BoardArray1D(3,3,arr2);	// Down version
	boardArray1D2.set_game_format(1);
	BoardArray1D boardArray1D3 = new BoardArray1D(3,3,arr3);	// Left version
	boardArray1D3.set_game_format(1);
	BoardArray1D boardArray1D4 = new BoardArray1D(3,3,arr4);	// Illegal move
	boardArray1D4.set_game_format(1);
	BoardArray1D boardArray1D5 = new BoardArray1D(3,3,arr5);	// Left version
	boardArray1D5.set_game_format(1);

	abstractBoard1[0] = boardArray1D1;
	abstractBoard1[1] = boardArray1D2;
	abstractBoard1[2] = boardArray1D3;
	abstractBoard1[3] = boardArray1D4;
	abstractBoard1[4] = boardArray1D5;

	/*  Testing of first parameter abstractBoard1  */
	/*  This array of references, points to a wrong sequence of moves  */

	System.out.println("************* TEST - 1 **************");
	System.out.println("Sequence of boards :");
	System.out.println(boardArray1D1);    
	System.out.println("Down version");       
	System.out.println(boardArray1D2); 
	System.out.println("Left version");
	System.out.println(boardArray1D3); 
	System.out.println("Illegal move");
	System.out.println(boardArray1D4); 
	System.out.println("Left version of Illegal move");
	System.out.println(boardArray1D5); 

	System.out.println("This test includes a wrong sequence of moves, it should give us false");
	System.out.print("Result: ");
	System.out.println(AbstractBoard.checkValidity(abstractBoard1));

/* ----------------------------------------------------------------------------------------------------*/


	/*  Create a random BoardArray2D objects for testing  */
	int [][] a1  = {{1,3,5},
	   	        	{8,-1,2},
					{4,6,7}		
			       };
	int [][] a2  = {{1,-1,5},
				 	{8,3,2},
					{4,6,7}		
				   };
	int [][] a3  = {{-1,1,5},
					{8,3,2},
					{4,6,7}		
			       };
	int [][] a4  = {{8,1,5},
				    {-1,3,2},
			        {4,6,7}		
			 	   };
	int [][] a5  = {{8,1,5},
					{3,-1,2},
					{4,6,7}		
				   };
	int [][] a6  = {{8,1,5},
					{3,2,-1},
					{4,6,7}		
				   };
	int [][] a7  = {{8,1,5},
					{3,2,7},
					{4,6,-1}		
			       };

	/*  Sequence is correct  */ 
	BoardArray2D boardArray2D1 = new BoardArray2D(3,3,a1);
	boardArray2D1.set_game_format(1);
	BoardArray2D boardArray2D2 = new BoardArray2D(3,3,a2); 
	boardArray2D2.set_game_format(1);
	BoardArray2D boardArray2D3 = new BoardArray2D(3,3,a3); 
	boardArray2D3.set_game_format(1);
	BoardArray2D boardArray2D4 = new BoardArray2D(3,3,a4); 
	boardArray2D4.set_game_format(1);
	BoardArray2D boardArray2D5 = new BoardArray2D(3,3,a5); 
	boardArray2D5.set_game_format(1);
	BoardArray2D boardArray2D6 = new BoardArray2D(3,3,a6); 	
	boardArray2D6.set_game_format(1);
	BoardArray2D boardArray2D7 = new BoardArray2D(3,3,a7); 
	boardArray2D7.set_game_format(1);

	abstractBoard2[0] = boardArray2D1;
	abstractBoard2[1] = boardArray2D2;
	abstractBoard2[2] = boardArray2D3;
	abstractBoard2[3] = boardArray2D4;
	abstractBoard2[4] = boardArray2D5;
	abstractBoard2[5] = boardArray2D6;
	abstractBoard2[6] = boardArray2D7;


	/*  Testing of second parameter abstractBoard2  */
	/*  This array of references, points to a correct sequence of moves  */
	System.out.println();
	System.out.println();
	System.out.println("************* TEST - 2 **************");
	System.out.println("Sequence of boards : ");
	System.out.println(boardArray2D1);
	System.out.println("Up version ");
	System.out.println(boardArray2D2); 
	System.out.println("Left version ");
	System.out.println(boardArray2D3);
	System.out.println("Down version ");
	System.out.println(boardArray2D4);
	System.out.println("Right version ");
	System.out.println(boardArray2D5);
	System.out.println("Right version ");
	System.out.println(boardArray2D6);
	System.out.println("Down version");
	System.out.println(boardArray2D7);

	System.out.println("This test includes a correct sequence of moves, it should give us true");
	System.out.print("Result: ");
	System.out.println(AbstractBoard.checkValidity(abstractBoard2));

/* ----------------------------------------------------------------------------------------------------*/


	/*  abstractBoard3 array of references, points both BoardArray2D and BoardArray1D objects.  */ 
	int [] arr6 = {8,1,5,-1,3,2,4,6,7};
	int [] arr7 = {8,1,5,3,-1,2,4,6,7};
	BoardArray1D boardArray1D6 = new BoardArray1D(3,3,arr6); 	
	boardArray1D6.set_game_format(1);
	BoardArray1D boardArray1D7 = new BoardArray1D(3,3,arr7);	
	boardArray1D7.set_game_format(1);

	abstractBoard3[0] = boardArray2D1;
	abstractBoard3[1] = boardArray2D2;
	abstractBoard3[2] = boardArray2D3;
	abstractBoard3[3] = boardArray1D6;
	abstractBoard3[4] = boardArray1D7;


	/*  Testing of third parameter abstractBoard3  */
	/*  This array of references, points to a correct sequence of moves  */
	System.out.println();
	System.out.println();
	System.out.println("************* TEST - 3 **************");
	System.out.println("Sequence of boards : ");
	System.out.println(boardArray2D1);
	System.out.println("Up version ");
	System.out.println(boardArray2D2);
	System.out.println("Left version ");
	System.out.println(boardArray2D3);
	System.out.println("Down version ");
	System.out.println(boardArray1D6);
	System.out.println("Right version ");
	System.out.println(boardArray1D7);

	System.out.println("This test includes a correct sequence of moves, it should give us true");
	System.out.println("Result: ");
	System.out.println(AbstractBoard.checkValidity(abstractBoard3));

/* ----------------------------------------------------------------------------------------------------*/


	/*  Create a random BoardArray2D objects for testing  */
	int [][] _array1 = {{1,0,9,0},
					     {5,6,8,3},
					     {2,-1,7,4}
					    };


	int [][] _array2 = {{1,0,9,0},
					     {5,-1,8,3},
					     {2,6,7,4}
					    };

	int [][] _array3 = {{1,-1,9,0},
					     {5,0,8,3},
					     {2,6,7,4}
					    };


	BoardArray2D boardArray2D1_ = new BoardArray2D(3,4,_array1);  // Initial board
	boardArray2D1_.set_game_format(2);
	BoardArray2D boardArray2D2_ = new BoardArray2D(3,4,_array2);  // Up version
	boardArray2D2_.set_game_format(2);
	BoardArray2D boardArray2D3_ = new BoardArray2D(3,4,_array3);  // Illegal move, it moves up, but upper tile was imposible tile.
	boardArray2D3_.set_game_format(2);

	abstractBoard4[0] = boardArray2D1_;
	abstractBoard4[1] = boardArray2D2_;
	abstractBoard4[2] = boardArray2D3_;

	/*  Testing of fourth parameter abstractBoard4  */
	/*  This array of references, points to a wrong sequence of moves  */
	System.out.println();
	System.out.println();
	System.out.println("************* TEST - 4 **************");
	System.out.println("Sequence of boards : ");
	System.out.println(boardArray2D1_);
	System.out.println("Up version ");
	System.out.println(boardArray2D2_); 
	System.out.println("Illegal move ");
	System.out.println(boardArray2D3_);

	System.out.println("This test includes a wrong sequence of moves, it should give us false");
	System.out.println("Result: ");
	System.out.println(AbstractBoard.checkValidity(abstractBoard4));

/* ----------------------------------------------------------------------------------------------------*/

	/*  abstractBoard5 array of references, points both BoardArray1D and BoardArray2D objects.  */
	int [][] ar1  = {{1,0,9,0},
					 {-1,5,8,3},
					 {2,6,7,4}		
				    };

	int [][] ar2  = {{1,0,9,0},
					 {5,-1,8,3},
					 {2,6,7,4}		
				    };

	int [][] ar3  = {{1,0,9,0},
					 {5,8,-1,3},
					 {2,6,7,4}
					};

	int [][] ar4  = {{1,0,9,0},
					 {5,8,2,3},
					 {-1,6,7,4}
			    	};	

	int [] ar5    ={1,0,9,0,-1,8,2,3,5,6,7,4};

	int [] ar6    ={1,0,9,0,8,-1,2,3,5,6,7,4}; 					    	

	BoardArray2D board_arr1 = new BoardArray2D(3,4,ar1);
	board_arr1.set_game_format(2);
	BoardArray2D board_arr2 = new BoardArray2D(3,4,ar2); 
	board_arr2.set_game_format(2);
	BoardArray2D board_arr3 = new BoardArray2D(3,4,ar3); 
	board_arr3.set_game_format(2);
	BoardArray2D board_arr4 = new BoardArray2D(3,4,ar4); 
	board_arr4.set_game_format(2);
	BoardArray1D board_arr5 = new BoardArray1D(3,4,ar5); 
	board_arr5.set_game_format(2);
	BoardArray1D board_arr6 = new BoardArray1D(3,4,ar6); 
	board_arr6.set_game_format(2);

	abstractBoard5[0] = board_arr1;
	abstractBoard5[1] = board_arr2;
	abstractBoard5[2] = board_arr3;
	abstractBoard5[3] = board_arr4;
	abstractBoard5[4] = board_arr5;
	abstractBoard5[5] = board_arr6;

	/*  Testing of fifth parameter abstractBoard5  */
	/*  This array of references, points to a wrong sequence of moves  */
	System.out.println();
	System.out.println();
	System.out.println("************* TEST - 5 **************");
	System.out.println("Sequence of boards : ");
	System.out.println(board_arr1);
	System.out.println("Right version ");
	System.out.println(board_arr2); 
	System.out.println("Right version ");
	System.out.println(board_arr3);
	System.out.println("Illegal move ");
	System.out.println(board_arr4);
	System.out.println("Up version ");
	System.out.println(board_arr5);
	System.out.println("Right move ");
	System.out.println(board_arr6);

	System.out.println("This test includes a wrong sequence of moves, it should give us false");
	System.out.print("Result: ");
	System.out.println(AbstractBoard.checkValidity(abstractBoard5));

	}

	catch(Exception e)
	{
		System.out.println("Exception caught : " + e);
	}

	}
}