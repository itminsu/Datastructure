#include "stack.h"
#include "solver.h"

using namespace std;

Solver::Solver()
	: maze(0), priorityDirection(DOWN)
{
}

Solver::~Solver()
{
	while (maze != NULL)
	{
		maze = 0;

	}
}

void Solver::InitialzeMaze(char* fileName) {

	ifstream is(fileName, ifstream::binary);
	if (is) {
		char c;
		int lineNumber = 1;
		while (is.get(c)) {
			if (c == '\n')
				++lineNumber;
		}
		is.clear();

		// get length of file:
		is.seekg(0, is.end); //move position to end of the stream
		totalLength = is.tellg(); //get length
		is.seekg(0, is.beg); //move position to beginning of the stream

		maze = new char[totalLength];

		// read data as a block:
		is.read(maze, totalLength);

		if (is)
			cout << "all characters read successfully." << endl;
		else
			cout << "error: only " << is.gcount() << " could be read";
		is.close();

		// ...buffer contains the entire file...

		lineEnd = totalLength / lineNumber;
		startPoint = lineEnd + 1;
		endPoint = (totalLength - 1) - lineEnd - 1;
		currPoint = startPoint;
	}
	else {
		cout << "Be able to read file!!" << endl;
	}
}

void Solver::MazeRunner() {
	int direction = 0;
	Stack stack;
	Stack junctionStack;
	Stack counterStack;
	int jCount = 1;
	while (true) {
		for (int i = 0; i < totalLength; i++) {

			if (i == currPoint && maze[currPoint] == ' ') {

				maze[i] = '#';
				currPoint = i;
				stack.Push(i);

				ValidPosition();

				if (GetJunctionCnt(currPoint) > 1) {
					counterStack.Push(GetJunctionCnt(currPoint));
					jCount = GetJunctionCnt(currPoint);
					junctionStack.Push(currPoint);
				}



				if (blockFlag) {
					jCount--;
					//while (returnStack.HasNext()) {

					int rPoint = junctionStack.Peek();

					while (stack.HasNext()) {
						int ppp = stack.Peek();

						maze[ppp] = ' ';
						stack.Pop();
						if (ppp == rPoint) {
							blockFlag = false;
							break;
						}
					}

					currPoint = rPoint;

					junctionStack.Pop();
					counterStack.Pop();
					//}	

					priorityDirection++;
					if (priorityDirection > LEFT) {
						priorityDirection = DOWN;
					}
				}

			}

		}//end for loop	

		 //if maze is solved, break loop and display message;
		if (maze[endPoint] == '#') {
			cout << "Solved Maze!!";
			break;
		}

	}//end while
}

void Solver::ValidPosition() {
	//down first.
	if (priorityDirection == DOWN) {
		//move down
		if (maze[currPoint] == '#' && maze[currPoint + (lineEnd + 1)] == ' ') {
			currPoint = currPoint + (lineEnd + 1);
		}
		// move right
		else if (maze[currPoint] == '#' && maze[currPoint + 1] == ' ') {
			currPoint = currPoint + 1;
		}
		//up
		else if (maze[currPoint] == '#' && maze[currPoint - (lineEnd + 1)] == ' ') {
			currPoint = currPoint - (lineEnd + 1);
		}
		//left
		else if (maze[currPoint] == '#' && maze[currPoint - 1] == ' ') {
			currPoint = currPoint - 1;
		}

		else {
			blockFlag = true;
		}
	}
	else  if (priorityDirection == RIGHT) {
		// move right
		if (maze[currPoint] == '#' && maze[currPoint + 1] == ' ') {
			currPoint = currPoint + 1;
		}
		//up
		else if (maze[currPoint] == '#' && maze[currPoint - (lineEnd + 1)] == ' ') {
			currPoint = currPoint - (lineEnd + 1);
		}
		//left
		else if (maze[currPoint] == '#' && maze[currPoint - 1] == ' ') {
			currPoint = currPoint - 1;
		}
		//down
		else if (maze[currPoint] == '#' && maze[currPoint + (lineEnd + 1)] == ' ') {
			currPoint = currPoint + (lineEnd + 1);
		}
		else {
			blockFlag = true;
		}
	}
	else if (priorityDirection == UP) {
		//up
		if (maze[currPoint] == '#' && maze[currPoint - (lineEnd + 1)] == ' ') {
			currPoint = currPoint - (lineEnd + 1);
		}
		//left
		else if (maze[currPoint] == '#' && maze[currPoint - 1] == ' ') {
			currPoint = currPoint - 1;
		}
		//down
		else if (maze[currPoint] == '#' && maze[currPoint + (lineEnd + 1)] == ' ') {
			currPoint = currPoint + (lineEnd + 1);
		}
		// move right
		else if (maze[currPoint] == '#' && maze[currPoint + 1] == ' ') {
			currPoint = currPoint + 1;
		}


		else {
			blockFlag = true;
		}
	}
	else if (priorityDirection == LEFT) {
		//left
		if (maze[currPoint] == '#' && maze[currPoint - 1] == ' ') {
			currPoint = currPoint - 1;
		}
		//down
		else if (maze[currPoint] == '#' && maze[currPoint + (lineEnd + 1)] == ' ') {
			currPoint = currPoint + (lineEnd + 1);
		}
		// move right
		else if (maze[currPoint] == '#' && maze[currPoint + 1] == ' ') {
			currPoint = currPoint + 1;
		}

		//up
		else if (maze[currPoint] == '#' && maze[currPoint - (lineEnd + 1)] == ' ') {
			currPoint = currPoint - (lineEnd + 1);
		}
		else {
			blockFlag = true;
		}
	}

	for (int j = 0; j < totalLength; j++) {
		cout << maze[j];
	}
}

int Solver::GetJunctionCnt(int currPoint) {
	int cnt = 0;
	// move right
	if (maze[currPoint + 1] == ' ') {
		cnt++;
	}
	//left
	if (maze[currPoint - 1] == ' ') {
		cnt++;
	}
	//down
	if (maze[currPoint + (lineEnd + 1)] == ' ') {
		cnt++;
	}
	//up
	if (maze[currPoint - (lineEnd + 1)] == ' ') {
		cnt++;
	}

	return cnt;
}

void Solver::DisplayMaze() {
	if (maze != NULL) {
		cout << endl;
		for (int j = 0; j < totalLength; j++) {
			cout << maze[j];
		}
		cout << endl;
	}
	else {
		cout << "Maze does not exist!!" << endl;
	}

}








