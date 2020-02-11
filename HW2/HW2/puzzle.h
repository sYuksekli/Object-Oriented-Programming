#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>

const bool checkSolved(int ** arr,int row, int col, int fileFormat);
void findEmptyNode(int **arr, int row, int col, int * cur_i, int *cur_j);
int ** create2DMatrix(int size);
const bool checkValidty(int ** arr, int row, int col, int i,int j);
void fillRandom(int ** arr, int size);
void print2DMatrix(int ** arr,int size);
void print2DMatrix(int ** arr,int row, int col);
void moveDown(int ** arr,int size);
void moveDown(int ** arr,int row, int col);
void moveUp(int ** arr,int size);
void moveUp(int ** arr,int row, int col);
void moveLeft(int ** arr,int size);
void moveLeft(int ** arr,int row, int col);
void moveRight(int ** arr,int size);
void moveRight(int ** arr,int row, int col);
int findCloseness(int **arr, int size);
int findCloseness(int **arr, int row, int col);
const char IntelligentMove(int ** arr,int size);
const char IntelligentMove(int ** arr,int row, int col);
void Shuffle(int ** arr,int size);
void Shuffle(int ** arr,int row, int col);
void Exit();
bool getStuck(char * arrChoice, char intelligentMoveChoice, int currentSize);
void moveRandom(int** arr, int size);
void moveRandom(int** arr, int row, int col);
int findSolution(int** arr, int row, int col, int fileFormat);
void printReport(int *numberOfMoves, int move);
void saveGameBoard(int ** arr, int size);
void saveGameBoard(int ** arr, int row, int col);
std::string checkFileFormat(int * result);
int ** loadGameBoard(std::string fileName, int * size);
int ** loadGameBoard(std::string fileName, int * row, int * col);
int getInversionNumber(int **arr, int size);
int findBlankPosition(int ** arr, int size);
const bool checkSolvable(int ** arr, int size);
void Menu();
void Menu(int ** arr, int row, int col, int fileFormat);



#endif