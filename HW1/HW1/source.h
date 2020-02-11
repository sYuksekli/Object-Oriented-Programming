#ifndef SOURCE_H_
#define SOURCE_H_


bool checkSolved(int ** arr,int size);
void findEmptyNode(int **arr, int size, int * cur_i, int *cur_j);
int ** create2DMatrix(int size);
bool checkValidty(int ** arr, int size, int i,int j);
void fillRandom(int ** arr, int size);
void print2DMatrix(int ** arr,int size);
void moveDown(int ** arr,int size);
void moveUp(int ** arr,int size);
void moveLeft(int ** arr,int size);
void moveRight(int ** arr,int size);
int findCloseness(int **arr, int size);
char IntelligentMove(int ** arr,int size);
void Shuffle(int ** arr,int size);
void Exit();
int getInversionNumber(int **arr, int size);
int findBlankPosition(int ** arr, int size);
bool checkSolvable(int ** arr, int size);
void Menu();



#endif