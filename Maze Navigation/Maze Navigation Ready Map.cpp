#include <iostream>
#include <iomanip>
#include <array>

const size_t ROW = 12;
const size_t COL = 13;

int mazeTraverse(char maze[][COL] ,  int row, int col);
void printMaze(char maze[][COL] );
void backtracking(char maze[][COL], int *rowss, int *colss, int startR, int startC);

int main(void){

	char maze[ROW][COL] = {
	"############",
    "#..........#",
    "..#.#.####.#",
    "###.#....#.#",
    "#....###.#..",
    "####.#.#.#.#",
    "#..#.#.#.#.#",
    "##.#.#.#.#.#",
    "#........#.#",
    "######.###.#",
    "#......#...#",
    "############"
	};
	maze[2][0] = '-';
	if(mazeTraverse(maze, 2, 0))
		std::cout<< "Cikis Bulundu!" << std::endl;

	return 0;
}

int mazeTraverse(char maze[][COL] ,  int row, int col){

    int startPointRow = row;
    int startPointCol = col;

	int moveRow[4] = {-1, 1,  0, 0};
	int moveCol[4] = { 0, 0, -1,  1};

	if(maze[row][col + 1] == '\0')
		return 1;

	for(unsigned i = 0; i < 4 ; ++i){

		row = startPointRow + moveRow[i];
		col = startPointCol + moveCol[i];

		if(maze[row][col] == '.'){

			maze[row][col] = '-';
			std::cout<<"continues!"<<std::endl;

			printMaze(maze);

			if(mazeTraverse(maze, row, col))
				return 1;
			
			backtracking(maze, &row, &col, startPointRow, startPointCol);

		}else{
		    row -= moveRow[i];
		    col -= moveCol[i];
		}


	}
	return 0;

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

void backtracking(char maze[][COL], int *rowss, int *colss, int startR, int startC){
		maze[*rowss][*colss] = '.';
		*rowss = startR;
		*colss = startC;
		std::cout<<"Opps CAME BACK AWAY!" << std::endl;
		printMaze(maze);
}
