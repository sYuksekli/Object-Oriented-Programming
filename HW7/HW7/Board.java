import java.lang.IllegalArgumentException;

public interface Board
{

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
	* Returns true if the baords are equal to each other.Last move, number of moves are ignored.
	* @param otherBoard is the board that will be compared.
	*/
	public abstract boolean Equals(AbstractBoard otherBoard);

	/**
	* Returns the number of column of the board.
	*/
	public abstract int getCol();

	/**
	* Returns the number of the row of the board.
	*/
	public abstract int getRow();

	/**
	* Sets game format. 1 represents HW1, 2 represents HW2 format.
	*/
	public abstract void set_game_format(int format);

	/**
	* Returns last move of this board. If there is no last move, it returns S.
	*/
	public abstract char lastMove();

	/**
	* Returns the number of moves this board made.
	*/
	public abstract int numberOfMoves();

}