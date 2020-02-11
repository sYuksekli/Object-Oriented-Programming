#include "puzzle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{	

	// If user enters input
	if (argc > 1)
	{
		
		int row = 0; 
		int col = 0;
		int size = 0;

		string line;
		string word;

		const auto blankStr = "bb";
		int fileFormat = 1;

		ifstream myfile(argv[1]);
		if (myfile.is_open())
	    {

    		while (getline (myfile,line)){ // To find number of rows
        		++row;

        		stringstream strStream(line);
        		while ( strStream >> word ){

        			// If board has bb, then its format like in HW2.
        			if (word.compare(blankStr) == 0) 
						fileFormat = 2;

        			++col;	// To find number of columns
        		} 		
    		}

    		col = col / row;

    		if (fileFormat == 2)
    		{
    			int ** str = (int **)malloc(sizeof(int*)*row);	// It creates array of file shape
				for (int i = 0; i < row; ++i) 
					str[i] = (int*)malloc(sizeof(int)*col); 

		
				int i = 0; // row
				int j = 0; // col

				string wordd;
				string line2;

				ifstream file(argv[1]);
				while (getline(file,line2)){   // It reads input text and stores it in an array.

					stringstream strStream2(line2);
					while(strStream2 >> wordd){

						if (wordd.compare(blankStr) == 0)
							str[i][j] = -1;
						
						else
							str[i][j] = stoi(wordd);
				
						++j;
					}

					j=0;
					++i;	
				}

				Menu(str,row,col,fileFormat);
  			}


  			else{

  				size = row;

	    		int ** str = (int **)malloc(sizeof(int*)*size);	
				for (int i = 0; i < size; ++i) 
					str[i] = (int*)malloc(sizeof(int)*size);


				char * strLine = (char*)malloc(sizeof(char)*(size+size)+size); 

				int i = 0; // row
				int j = 0; // col

				int count = 0;
				ifstream file2(argv[1]);
				string line3;

				while (getline(file2,line3)){

					line3.copy(strLine,line3.size()+1);	// It copies string to char array.
					strLine[line3.size()] = '\0';		


	     		   	// Stringstream does not read blank tile.
    	    		// It reads strings by getLine function.
       		 		// and checks if each line contains more spaces than usual. 
					for (int k = 0; k < line3.size(); ++k)
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
        						k = line3.size(); // To finish loop
        					}
        											 
        				}

        				else{

        					if(k == 0 && strLine[k] == ' '){

        						str[i][k] = -1;	  // If k equals to zero, it equals to real index.
        						k = line3.size(); // If k equals to zero, for loop has to end. 
        						++j;			  // because it can enter first if statement.
        					}
        				}
        			}

					string wordd;
					stringstream strStream(line3);
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

				Menu(str,size,size,fileFormat);
			}

			myfile.close();
		}

		else
			cout << "Unable to open file" << endl;
	}

	// If user does not enter any input, then format of HW1 game works.
	else
		Menu();


    return 0;
}