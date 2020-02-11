#include "NPuzzle.h"


int main(int argc, char const *argv[])
{	


	int size;					
	char choice;
	char IntelligentMoveChoice;

	int NforShuffle;			// it will be used as a shuffle parameter.
	int numberOfMove = 0;		// total number of moves until the problem is solved.
	int number; 				// this variable shows how many moves V command make.
	NPuzzle puzzle;				// Create an instance of NPuzzle.
	string fileName;

	// If user enters input
	if (argc > 1)
	{

										
		puzzle.setFormatChoice(2);						// and its game format.

		cout << "Your initial random board is" << endl;
		NforShuffle = puzzle.readFromFile(argv[1]);		// This function returns row*col value to be used in shuffle.

		do{
			cout << "Your move : ";
			cin >> choice;

			if (choice == 'D' || choice == 'd')
			{
				puzzle.move('D');
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'U' || choice == 'u')
			{
				puzzle.move('U');
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}	

			else if (choice == 'L' || choice == 'l')
			{
				puzzle.move('L');
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'R' || choice == 'r')
			{

				puzzle.move('R');
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'I' || choice == 'i')
			{

				IntelligentMoveChoice = puzzle.moveIntelligent();
				cout << "Intelligent move chooses " << IntelligentMoveChoice << endl;
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'S' || choice == 's')
			{	
				puzzle.shuffle(NforShuffle);
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'V' || choice == 'v')
			{
				number = puzzle.solvePuzzle();	
				puzzle.setNumberOfMoves(number);			
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
				cout << "Please enter legal moves (D, R, U, L, I, S, V, T, E, O, Q)" << endl;


		} while(puzzle.isSolved() != true && choice != 'Q' && choice != 'q');

		puzzle.printReport();
	}


	else
	{

		do{

			cout << "Please enter the problem size" << endl;
			cin >> size;

			if (size!= 3 && size!=4 && size!=5 && size!=6 && size!=7 && size!=8 && size!=9)
			{
				cout << "Please enter a legal size (3x3,4x4,5x5,.....,9x9)" << endl;
			}

		} while (size !=3 && size != 4 && size != 5 && size != 6 && size != 7 && size != 8 && size !=9);

		puzzle.setFormatChoice(1);		// set its game format to 1.
		puzzle.setsize(size,size);		// set its size according to the value that user entered.
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
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'U' || choice == 'u')
			{	
				puzzle.move('U');
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}	

			else if (choice == 'L' || choice == 'l')
			{
				puzzle.move('L');
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'R' || choice == 'r')
			{
				puzzle.move('R');
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'I' || choice == 'i')
			{
				IntelligentMoveChoice = puzzle.moveIntelligent();
				cout << "Intelligent move chooses " << IntelligentMoveChoice << endl;
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'S' || choice == 's')
			{
				puzzle.shuffle(size*size);
				puzzle.print();
				puzzle.setNumberOfMoves(1);
			}

			else if (choice == 'V' || choice == 'v')
			{
				number = puzzle.solvePuzzle();	
				puzzle.setNumberOfMoves(number);				
			}

			// If user wants to read some shape file while user was playing the game 
			// set game format to 2.
			else if (choice == 'O' || choice == 'o')
			{
				cout << "Enter a fileName" << endl;
				cin >> fileName;
				puzzle.setFormatChoice(2);			 
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
				cout << "Please enter legal moves (D, R, U, L, I, S, Q, V, T, E, O)" << endl;


		} while(puzzle.isSolved() != true && choice != 'Q' && choice != 'q');

		puzzle.printReport();
	}

    return 0;
}