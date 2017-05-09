#ifndef _SOLVER_H
#define _SOLVER_H

#include <fstream>
#include <iostream>
#include <string.h>
#include <direct.h>
using namespace std;
enum direction { DOWN, RIGHT, UP, LEFT };  //0,1,2,3

class Solver
{
	private:
		char *maze;
		int startPoint;
		int endPoint;
		int currPoint;
		int lineEnd;
		int totalLength;
		int priorityDirection;
		bool blockFlag = false;
	public:
		Solver();
		virtual ~Solver();

		void InitialzeMaze(char* fileName);
		int GetJunctionCnt(int currPoint);
		void MazeRunner();
		void DisplayMaze();
		void ValidPosition();
		friend ostream& operator<<(ostream& output, Solver& Solver);
};
#endif