import java.lang.IllegalArgumentException;
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

public class BoardArray1D extends AbstractBoard
{

	private int [] arr;


	/**
	* No Parameter Constructor.
	*/
	public BoardArray1D()
	{
		super();
		row = 3;
		col = 3;
		arr = new int[9];
	}

	/**
	* Constructor to initialize board according to given values.
	*/
	public BoardArray1D(int _row, int _col, int [] _arr)
	{
		super();
		row = _row;
		col = _col;
		arr = _arr;
	}

	/**
    * It returns a string that textually represents this object.
    * @return a string representation of the object
    */
	public String toString()
	{	
		String board = "";
		int k=0;
		if (game_format == 1)
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if(arr[k]==-1) 		// if it is blank tile, don't print to the screen.
						board+= "  ";
					else
						board+= arr[k] + " ";
					++k;
				}

				board+= "\n";
			}
		}

		else
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					if(arr[k] == -1) 
						board+= "bb ";	 // if it is blank tile, print as 'bb' to the screen.

					else if (arr[k] == 0)
						board+= "00 ";	 // It represents walls.
			
					else{

						if (arr[k] < 10)
							board+= "0" + arr[k] + " ";  // For one-digit numbers.
						else
							board+= arr[k] + " ";
					}

					++k;
				}

				board+= "\n";
			}
		}

		return String.format(board);
	}

	/**
	* Reads the game board from file.
	* @param fileName is the file name that contains board.
	*/
	public void readFromFile(String fileName)
	{
		try
		{
			int rowValue = 0;
			int colValue = 0;

			String row_str;
			String [] col_str = null;

			String blankStr = "bb";

			File file = new File(fileName);
			Scanner scanner = new Scanner(file); 

			while (scanner.hasNextLine()){        // To find number of rows.
        		++ rowValue;
				row_str = scanner.nextLine();
				col_str = row_str.split(" ");
    		}

    		colValue = col_str.length;			// To find the number of the columns.

   	 		// number of the current row and column can be different from size of the shape file.
    		// So it sets size of the board.
   			setSize(rowValue,colValue);

			int i = 0; 
			int j = 0;
			scanner = new Scanner(file);

			while (scanner.hasNextLine()){

				row_str = scanner.nextLine();
				System.out.println(row_str);	// It prints shape file to the screen.

				col_str = row_str.split(" ");
				while(j < col_str.length){

					if (col_str[j].equals(blankStr)){
						arr[i] = -1;
					}
				
					else{
						arr[i] = Integer.parseInt(col_str[j]);
					}
				
					++i;
					++j;
				}

				j = 0;		
			}
		
			LastMove = 'S';
			NumberOfMoves = 0;
		}

		catch(Exception e)
		{
			System.out.println("Exception caught : " + e);
		}
	}

	/**
	* Writes the game board to the file.
	* @param fileName is the file name that baord game will be written.
	*/
	public void writeToFile(String fileName)
	{	
		int k=0;
		FileWriter fileWriter = null;
		BufferedWriter out = null;
		String content ="";

		try
		{	
			
			fileWriter = new FileWriter(fileName);
			out = new BufferedWriter(fileWriter);
			for (int i = 0; i < getRow(); ++i)
			{
				for (int j = 0; j < getCol(); ++j)
				{
					if(arr[k]==-1) 			// bb is blank tile.
						out.write("bb ");

					else if (arr[k] == 0)	// 00 is wall.
						out.write("00 ");

					else{

						if (arr[k] < 10){
							out.write("0");
							content = Integer.toString(arr[k]);		// If number is one-digit
							out.write(content);
							out.write(" ");
						}

						else{
							content = Integer.toString(arr[k]);		// If number is one-digit
							out.write(content);
							out.write(" ");
						}
					}

					++k;
				}

				out.newLine();
			}
		}
		
		catch(Exception e)
		{
			System.out.println("Exception caught : " + e);
		}

		finally
		{	
			try
			{
				if (out != null) {
					out.close();
				}

				if (fileWriter != null) {
					fileWriter.close();
				}
			}

			catch(Exception e)
			{
				System.out.println("Exception caught " + e);
			}
			
		}
	}

	/**
	* Resets the board to the solution.
	*/
	public void reset()
	{
		int curVal = 1;
		int k = 0;
		if (game_format == 1)
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					arr[k] = curVal;
					++curVal;
			
					if (i == row-1 && j== col-1)
						arr[k] = -1;

					++k;				
				}
			}
		}

		else
		{
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{

					if (arr[k] != 0)
					{
						arr[k] = curVal;
						++curVal;
					}

					if (i == row-1 && j== col-1)
						arr[k] = -1;	
				
					++k;
				}
			}
		}
	}

	/**
	* Sets the board to given values.
	* @param rowValue represents number of row.
	* @param colValue represents number of col.
	*/
	public void setSize(int rowValue, int colValue)
	{	
		row = rowValue;
 		col = colValue;
 		arr = new int[row*col];
	}

	/**
	* Makes a move on board according to the parameter
	* @param move indicates the type of the move
	*/ 
	public void move(char move)
	{
		int k = 0;
		if (game_format == 2)
		{
			if (move == 'U')
			{
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[k]== -1 && (i-1)>=0 && arr[k-col] != 0)
						{
							arr[k] = arr[k-col];
							arr[k-col] = -1;
						}
						
						++k;
					}
				}
			}

			if (move == 'D')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[k]== -1 && (i+1)<row && arr[k+col] != 0)
						{
							arr[k] = arr[k+col];
							arr[k+col] = -1;
							return;	
							// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
						}

						++k;
					}	
				}
			}

			if (move == 'L')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[k]== -1 && (j-1)>=0 && arr[k-1] != 0)
						{
							arr[k] = arr[k-1];
							arr[k-1] = -1;
						}

						++k;
					}
				}
			}

			if (move == 'R')
			{	
				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[k]== -1 && (j+1)<col && arr[k+1] != 0)
						{
							arr[k] = arr[k+1];
							arr[k+1] = -1;
							return; 
							// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
						}

						++k;
					}
				}
			}
		} // end of the file format 2.


		else
		{
			if (move == 'D'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[k]== -1 && (i+1)<row )
						{
							arr[k] = arr[k+col];
							arr[k+col] = -1;
							return;	
							// The aim of using return is if the blank tile moves down, for loop will catch blank tile again.
						}

						++k;
					}
				}	
			}

			if (move == 'U'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[k]== -1 && (i-1)>=0 )
						{
							arr[k] = arr[k-col];
							arr[k-col] = -1;
						}

						++k;
					}
				}
			}

			if (move == 'L'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[k]== -1 && (j-1)>=0 )
						{
							arr[k] = arr[k-1];
							arr[k-1] = -1;
						}

						++k;
					}
				}
			}

			if (move == 'R'){

				++NumberOfMoves;
				LastMove = move;
				for (int i = 0; i < row; ++i)
				{
					for (int j = 0; j < col; ++j)
					{
						if (arr[k]== -1 && (j+1)<col )
						{
							arr[k] = arr[k+1];
							arr[k+1] = -1;
							return; 
							// The aim of using return is if the blank tile moves right, for loop will catch blank tile again.
						}

						++k;
					}
				}
			}
		} // end of the file format 1
	}

	/**
	* Returns true if the game is solved.
	*/
	public boolean isSolved()
	{
		int curVal = 1;
		int rowValue = row;
		int colValue = col;
		int k = 0;

		if (game_format == 1)		// For HW1 format
		{	
			for (int i = 0; i < rowValue; ++i){
		
				if(i == rowValue-1) // -1 represents blank tile. I reduce size, because last tile has to be blank. 
					colValue--;

				for (int j = 0; j < colValue; ++j){
					if(arr[k]!=curVal++){
						return false;	
					}
					++k;
				}
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
					if (arr[k] != 0) { 	 // 0 is the impossible tile.

						if (arr[k] != curVal++)
							return false;
						++k;
					}
				}
			} 	

			return true;
		}
	}

	/**
	* Returns the corresponding cell content of the board.
	* @param index1 represents the x-axis.
	* @param index2 represents the y-axis.
	* @throws IllegalArgumentException
	*/
	public int cell(int index1, int index2) throws IllegalArgumentException
	{
		if (index1 >= 0 && index2 >= 0 && index1 < row && index2 < col)
		{	
			int result = 0;
			int k = 0;
			for (int i = 0; i < row; ++i){
				for (int j = 0; j < col; ++j){
					if (i== index1 && j==index2)
						result = arr[k];
					else
						++k;
				}
			}

			return result;
		}

		else{

			throw new IllegalArgumentException();
		}
	}

	/**
	* Finds the x location of the blank tile.
	*/
	protected int findEmptyNodeXLocation(){

		int j = 0;
		int result = -1;
		for (int i = 0; i < row*col; ++i)
		{
			if (arr[i] == -1)
			{
				j = i / col;   // This type of board is represented with one-dimensional array
				result = j;    // But, it is actually two-dimensional. 
			}				   // So, I find the x coordinate of board like this.
		}

		return result;	
	}

	/**
	* Finds the y location of the blank tile.
	*/
	protected int findEmptyNodeYLocation(){

		int j = 0;
		int result = -1;
		for (int i = 0; i < row*col; ++i)
		{
			if (arr[i] == -1)
			{
							 // This type of board is represented with one-dimensional array
				j = i % col; // But, it is actually two-dimensional. So, I find the y coordinate
				result = j;	 // of board like this.
			}
		}

		return result;	
	}

}