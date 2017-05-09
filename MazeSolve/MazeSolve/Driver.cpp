#include <conio.h>
#include "stack.h"
#include "solver.h"

using namespace std;


int main()
{
	Solver mazeSolver;

	char *fileName = "maze.txt";
	
	bool loopFlag = true;
	while (loopFlag) {
		cout << "1:maze, 2:maze2, 3:maze3, 4:maze4, 5:mazeX" << endl;
		cout << "Select Maze name that you want to solve (q:quit):" << endl;

		char input;
		input = _getch();

		switch (input)
		{
		case '1':
			fileName = "maze.txt";
			break;
		case '2':
			fileName = "maze2.txt";
			break;
		case '3':
			fileName = "maze3.txt";
			break;
		case '4':
			fileName = "maze4.txt";
			break;
		case '5':
			fileName = "mazex.txt";
			break;
		case 'q':
			exit(0);
			break;
		default:
			cout << "Please select numbers between 1 to 5";
			break;
		}


		mazeSolver.InitialzeMaze(fileName);
		mazeSolver.MazeRunner();
		mazeSolver.DisplayMaze();

		_getch();
	}

	cin.ignore();

	return 0;
}