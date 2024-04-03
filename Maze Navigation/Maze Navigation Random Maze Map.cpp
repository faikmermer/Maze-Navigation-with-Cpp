#include <iostream>
#include <iomanip>
#include <array>
#include <random>

const size_t ROW = 12;
const size_t COL = 13;

void randomMazeMap(char maze[][COL]);
void printMaze(char maze[][COL]);
void backtracking(char maze[][COL], int *rowss, int *colss, int prevRow, int prevCol);
int mazeTraverse(char maze[ROW][COL], int row, int col);

int main(void){
	std::srand(static_cast<unsigned int>(time(0)));

	int startPointRow = rand() % 12;
    int startPointCol = rand() % 12;
    int finishPointRow = rand() % 12;
	int finishPointCol = rand() % 12;

	if(startPointCol != 0){
        startPointRow = 0;
	}

    if(finishPointCol != 11){
        finishPointRow = 11;
    }


	char maze[ROW][COL];

	for(unsigned int i = 0; i < 12; ++i){
		for(unsigned int j = 0; j < 12; ++j){
			maze[i][j] = '#';
		}
	}
	maze[startPointRow][startPointCol] = 'o';
	maze[finishPointRow][finishPointCol] = '.';

	randomMazeMap(maze);
	std::cout<<"This is Maze Map\n";
	printMaze(maze);

	if(!mazeTraverse(maze, startPointRow, startPointCol))
		std::cout<<"This maze map not out!";
	else
		std::cout<<"Find out !";
}


void randomMazeMap(char maze[][COL]){
	
	std::srand(static_cast<unsigned int>(time(0)));
	
	int road; 
		
	for(unsigned int i = 1; i < 11; ++i){
		for(unsigned int j = 1; j < 12; ++j){
		    road = 1 + rand() % 10; 
			if(road % 2 == 0){
				maze[i][j] = '.';
			}
		}
		std::cout<<std::endl;
	}
}


int mazeTraverse(char maze[ROW][COL], int row, int col){

	int startPointRow = row;
    int startPointCol = col;

	int moveRow[4] = {-1, 1,  0, 0};
	int moveCol[4] = { 0, 0, -1, 1};

	if(maze[row][col + 1] == '\0'){
		return 1;
	}

	for(unsigned int i = 0; i < 4; ++i){
		
		row = startPointRow + moveRow[i];
		col = startPointCol + moveCol[i];

		if(maze[row][col] == '.'){

			maze[row][col] = 'o';
			std::cout<<"continues !\n";
			printMaze(maze);

			if(mazeTraverse(maze, row, col))
				return 1;

			backtracking(maze, &row, &col, startPointRow, startPointCol);
		}else{
			row -= startPointRow;
			col -= startPointCol;
		}

	}
	return 0;
}


void backtracking(char maze[][COL], int *rowss, int *colss, int prevRow, int prevCol){
	maze[*rowss][*colss] = '.';
	std::cout<<"Opps CAME BACK AWAY!" << std::endl;
	*rowss = prevRow;
	*colss = prevCol;
	printMaze(maze);
}


void printMaze(char maze[][COL]){
	for(unsigned int i = 0; i <  12; ++i){
		for(unsigned int j = 0; j < 12; ++j){
			std::cout<<maze[i][j];
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}
