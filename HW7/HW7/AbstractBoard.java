import java.lang.IllegalArgumentException;
import java.lang.Math;


public abstract class AbstractBoard implements Board
{
	protected int game_format;
	protected static int numberOfBoards = 0;
	protected int NumberOfMoves;
	protected char LastMove;
	protected int row;
	protected int col;

	/**
	* Finds the x location of the blank tile.
	*/
	protected abstract int findEmptyNodeXLocation();

	/**
	* Finds the y location of the blank tile.
	*/
	protected abstract int findEmptyNodeYLocation();

	/**
    * It returns a string that textually represents this object.
    * @return a string representation of the object
    */
	public abstract String toString();

	/**
	* Reads the game board from file.
	* @param fileName is the file name that contains board.
	*/
	public abstract void readFromFile(String fileName);

	/**
	* Writes the game board to the file.
	* @param fileName is the file name that baord game will be written.
	*/
	public abstract void writeToFile(String fileName);

	/**
	* Resets the board to the solution.
	*/
	public abstract void reset();

	/**
	* Sets the board to given values.
	* @param rowValue represents number of row.
	* @param colValue represents number of column.
	*/
	public abstract void setSize(int rowValue, int colValue);

	/**
	* Makes a move on board according to the parameter
	* @param move indicates the type of the move
	*/ 
	public abstract void move(char move);

	/**
	* Returns true if the game is solved.
	*/
	public abstract boolean isSolved();

	/**
	* Returns the corresponding cell content of the board.
	* @param index1 represents the x-axis.
	* @param index2 represents the y-axis. 
	* @throws IllegalArgumentException if the indexes are invalid.
	*/
	public abstract int cell(int index1, int index2) throws IllegalArgumentException;


	/**
	* No parameter constructor
	*/
	public AbstractBoard()
	{
		LastMove = 'S';
		NumberOfMoves = 0;
		game_format = -1;
		++numberOfBoards;
		row = 0;
		col = 0;
	}

	/**
	* Returns true if the baords are equal to each other.Last move, number of moves are ignored.
	* @param otherBoard is the board that will be compared.
	*/
	public boolean Equals(AbstractBoard otherBoard)
	{
		for (int i = 0; i < otherBoard.getRow(); ++i)
		{
			for (int j = 0; j < otherBoard.getCol(); ++j)
			{
				if (this.cell(i,j) != otherBoard.cell(i,j))
				{
					return false;
				}
			}
		}
		
		return true;
	}

	/**
	* Returns the number of column of the board.
	*/
	public int getCol()
	{
		return col;
	}

	/**
	* Returns the number of the row of the board.
	*/
	public int getRow()
	{
		return row;
	}

	/**
	* Sets game format. 1 represents HW1, 2 represents HW2 format.
	*/
	public void set_game_format(int format)
	{
		game_format = format;
	}

	/**
	* Returns the number of boards created so far.
	*/
	public static int NumberOfBoards()
	{
		return numberOfBoards;
	}
	
	/**
	* Returns last move of this board. If there is no last move, it returns S.
	*/
	public char lastMove()
	{
		return LastMove;
	}

	/**
	* Returns the number of moves this board made.
	*/
	public int numberOfMoves()
	{
		return NumberOfMoves;
	}


	/**
	* Returns true if the array contains a valid sequence for a solution. 
	*/
	public static boolean checkValidity(AbstractBoard [] boards)
	{	

		int size = boards.length;

		int cur_i = 0;
 		int cur_j = 0;
 		int next_cur_i = 0;
 		int next_cur_j = 0;

 		int value = 0;
 		int i_distance = 0;
 		int j_distance = 0;

 		/* Cast the current and the next element to understand what type of an object it points*/
 		for (int i = 0; i < size-1; ++i)
 		{		

 			// Find the positions of the blank tile of the next node.
 			if (boards[i+1] instanceof BoardArray2D) {
 				BoardArray2D board2D_next = (BoardArray2D) boards[i+1];
 				next_cur_i = board2D_next.findEmptyNodeXLocation();
 				next_cur_j = board2D_next.findEmptyNodeYLocation();
 			}

 			if (boards[i+1] instanceof BoardArray1D) {
 				BoardArray1D board1D_next = (BoardArray1D) boards[i+1];
 				next_cur_i = board1D_next.findEmptyNodeXLocation();
 				next_cur_j = board1D_next.findEmptyNodeYLocation();
 			}

 			// Find the positions of the blank tile of the current node.
 			// value variable is needed to understand if blank tile switches place with imposible tile.
 			if (boards[i] instanceof BoardArray2D) {
 				BoardArray2D board2D = (BoardArray2D) boards[i];
 				cur_i = board2D.findEmptyNodeXLocation();
 				cur_j = board2D.findEmptyNodeYLocation();
 				value = board2D.cell(next_cur_i,next_cur_j);
 			}

 			if (boards[i] instanceof BoardArray1D) {
 				BoardArray1D board1D = (BoardArray1D) boards[i];
 				cur_i = board1D.findEmptyNodeXLocation();
 				cur_j = board1D.findEmptyNodeYLocation();
 				value = board1D.cell(next_cur_i,next_cur_j);
 			}

			
			// find the distance  between
			// position of blank tile of current element and position of blank tile of next element
			i_distance = Math.abs(cur_i - next_cur_i);
 			j_distance = Math.abs(cur_j - next_cur_j);
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