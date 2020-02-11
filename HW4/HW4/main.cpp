#include "NPuzzle.h"


int main(int argc, char const *argv[])
{	

	int size;					
	char choice;
	char IntelligentMoveChoice;
	int NforShuffle;
	string fileName;

	NPuzzle puzzle;				// Create an instance of NPuzzle.
	
	// If user enters input
	if (argc > 1)
	{
								
		puzzle.setGameFormat(2);						// set its game format to 2.

		cout << "Your initial random board is" << endl;
		NforShuffle = puzzle.readFromFile(argv[1]);		// This function returns row*col value to be used in shuffle.


		do{
			cout << "Your move : ";
			cin >> choice;

			if (choice == 'D' || choice == 'd')
			{
				puzzle.move('D');
				puzzle.print();
			}

			else if (choice == 'U' || choice == 'u')
			{
				puzzle.move('U');
				puzzle.print();
			}	

			else if (choice == 'L' || choice == 'l')
			{
				puzzle.move('L');
				puzzle.print();
			}

			else if (choice == 'R' || choice == 'r')
			{

				puzzle.move('R');
				puzzle.print();
			}

			else if (choice == 'S' || choice == 's')
			{	
				puzzle.shuffle(NforShuffle);
				puzzle.print();
			}

			else if (choice == 'V' || choice == 'v')
			{
				puzzle.solvePuzzle(2);				
			}

			else if (choice == 'E' || choice == 'e')
			{	
				cout << "Enter a fileName" << endl;
				cin >> fileName;
				puzzle.writeToFile(fileName);
			}

			else if (choice == 'O' || choice == 'o')
			{
				cout << "Enter a fileName" << endl;
				cin >> fileName;
				NforShuffle = puzzle.readFromFile(fileName);
			}

			else if (choice == 'T' || choice == 't')
				puzzle.printReport();

			else if (choice == 'Q' || choice == 'q')
				cout<< "Game is terminated!" << endl;

			else
				cout << "Please enter legal moves (D, R, U, L, S, V, T, E, O, Q)" << endl;


		} while(puzzle.isSolved() != true && choice != 'Q' && choice != 'q');

		puzzle.printReport();
	}


	else
	{

		int format = 1;

		do{

			cout << "Please enter the problem size" << endl;
			cin >> size;

			if (size!= 3 && size!=4 && size!=5 && size!=6 && size!=7 && size!=8 && size!=9)
				cout << "Please enter a legal size (3x3,4x4,5x5,.....,9x9)" << endl;
			
		} while (size !=3 && size != 4 && size != 5 && size != 6 && size != 7 && size != 8 && size !=9);


		NforShuffle = size*size;			// Until reads a file, we know the shuffle parameter.
		puzzle.setGameFormat(format);		// set its game format to 1 initially.
		puzzle.setsize(size,size);			// set its size according to the value that user entered.
		srand(time(NULL));


		// if game is not solvable, create a random board until it is solvable.
		do{
			puzzle.fillRandom();
		} while(puzzle.checkSolvable() != true); 


		cout << "Your initial random board is" << endl;
		puzzle.print();

	
		do{

			cout << "Your move : ";
			cin >> choice;

			if (choice == 'D' || choice == 'd')
			{
				puzzle.move('D');
				puzzle.print();
			}

			else if (choice == 'U' || choice == 'u')
			{	
				puzzle.move('U');
				puzzle.print();
			}	

			else if (choice == 'L' || choice == 'l')
			{
				puzzle.move('L');
				puzzle.print();
			}

			else if (choice == 'R' || choice == 'r')
			{
				puzzle.move('R');
				puzzle.print();
			}

			else if (choice == 'S' || choice == 's')
			{
				puzzle.shuffle(NforShuffle);
				puzzle.print();
			}

			else if (choice == 'V' || choice == 'v')
			{
				puzzle.solvePuzzle(format);					
			}

			// If user wants to read some shape file while user was playing the game 
			// set game format to 2.
			else if (choice == 'O' || choice == 'o')
			{
				cout << "Enter a fileName" << endl;
				cin >> fileName;
				format = 2;
				puzzle.setGameFormat(format);			 
				NforShuffle = puzzle.readFromFile(fileName);
			}
			
			// This E command makes sense if the user has read the game from the file and continues to play it. 
			else if (choice == 'E' || choice == 'e')
			{	
				cout << "Enter a fileName" << endl;
				cin >> fileName;
				puzzle.writeToFile(fileName);
			}

			else if (choice == 'T' || choice == 't')
				puzzle.printReport();

			else if (choice == 'Q' || choice == 'q')
				cout<< "Game is terminated!" << endl;

			else
				cout << "Please enter legal moves (D, R, U, L, S, Q, V, T, E, O)" << endl;


		} while(puzzle.isSolved() != true && choice != 'Q' && choice != 'q');

		puzzle.printReport();
	}

    return 0;
}