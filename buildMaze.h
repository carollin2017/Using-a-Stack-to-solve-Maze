#pragma once
#include <iostream>
#include <stack>
#include <time.h>
using namespace std;


class Maze 
{
protected:
	int row, col;
public:
	
	void printMaze(int** maze, int row, int col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << maze[i][j] << " ";
			}
			cout << endl;
		}
	}

	int** buildMaze(int row, int col) {
		srand(time(0));
		int** matrix =  new int* [row];
		//randomly generate a  matrix
		//0 represents wall, 1 represents hall that we can go through.
		for (int i = 0; i < row; i++) {
			matrix[i] = new int[col];
			for (int j = 0; j < col; j++) {
				matrix[i][j] = rand() % 2;
			}
		}
		cout << "The maze is: " << endl;
		printMaze(matrix, row, col);

		return matrix;
	}

	bool** isVisited(int row, int col) {
		bool** visited = new bool*[row];
		for (int i = 0; i < row; i++) {
			visited[i] = new bool[col];
			for (int j = 0; j < col; j++) {
				//initially setting the matrix as unvisisted.
				visited[i][j] = false;
			}
		}

		
		return visited;
	}


};

