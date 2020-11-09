#pragma once
#include "buildMaze.h"
#include "Location.h"

using namespace std;

class SolveMaze{
public:
	//We build the maze randomly, and try to find a path.
	bool isRandomMazeReachable(int row, int col, int x, int y) {
		Maze m;
		//build a random maze
		int** maze = m.buildMaze(row, col);
		//set up a same size matrix as maze to keep track if the current location is visited.
		bool** visited = m.isVisited(row, col);
		
		stack<Location> stack;
		//We assume that we always start at maze[0][0].
		int i = 0, j = 0;
		Location start(i, j);
		stack.push(start);
		

		while (!stack.empty()) {
			Location cur = stack.top();
			//get the coordinates and direction of the current location.
			int d = cur.dir;
			i = cur.x;
			j = cur.y;

			cur.dir++;
			stack.pop();
			stack.push(cur);

			//arrive destination
			if (i == x && j == y) {
				//visited[0][0] = true;
				cout << "The Path is: " << endl;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cout << visited[i][j] << " ";
					}
					cout << endl;
				}
				return true;
			}

			//checking up
			if (d == 0) {
				if (i - 1 >= 0 && maze[i - 1][j] && !visited[i - 1][j]) {
					Location up(i - 1, j);
					visited[i - 1][j] = true;
					stack.push(up);
				}
			}
			//checking right
			else if (d == 1) {
				if (j + 1 < col && maze[i][j + 1] && !visited[i][j + 1]) {
					Location right(i, j + 1);
					visited[i][j + 1] = true;
					stack.push(right);
				}
			}
			//checking down
			else if (d == 2) {
				if (i + 1 < row && maze[i + 1][j] && !visited[i + 1][j]) {
					Location down(i + 1, j);
					visited[i + 1][j] = true;
					stack.push(down);
				}
			}
			//checking left
			else if (d == 3) {
				if (j - 1 >= 0 && maze[i][j - 1] && !visited[i][j - 1]) {
					Location left(i, j - 1);
					visited[i][j - 1] = true;
					stack.push(left);
				}
			}

			else {
				visited[cur.x][cur.y] = false;
				stack.pop();
			}
		}

		return false;
	}


	//Given a 10 * 10 maze, we find a path.
	bool isMazeReachable(int maze[][10], int row, int col, int x, int y) {
		//set up a same size matrix as maze to keep track if the current location is visited.
		bool visited[10][10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				//initially setting the matrix as unvisisted.
				visited[i][j] = false;
			}
		}

		//We assume that we always start at maze[0][0].
		int i = 0, j = 0;
		stack<Location> stack;
		Location temp(i, j);
		stack.push(temp);

		while (!stack.empty()) {
			Location cur = stack.top();
			//get the coordinates and direction of the current location.
			int d = cur.dir;
			i = cur.x;
			j = cur.y;

			cur.dir++;
			stack.pop();
			stack.push(cur);

			if (i == x && j == y) {
				cout << "The Path is: " << endl;
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cout << visited[i][j] << " ";
					}
					cout << endl;
				}
				return true;
			}

			if (d == 0) {
				if (i - 1 >= 0 && maze[i - 1][j] && !visited[i - 1][j]) {
					Location up(i - 1, j);
					visited[i - 1][j] = true;
					stack.push(up);
				}
			}

			else if (d == 1) {
				if (j + 1 < col && maze[i][j + 1] && !visited[i][j + 1]) {
					Location right(i, j + 1);
					visited[i][j + 1] = true;
					stack.push(right);
				}
			}

			else if (d == 2) {
				if (i + 1 < row && maze[i + 1][j] && !visited[i + 1][j]) {
					Location down(i + 1, j);
					visited[i + 1][j] = true;
					stack.push(down);
				}
			}

			else if (d == 3) {
				if (j - 1 >= 0 && maze[i][j - 1] && !visited[i][j - 1]) {
					Location left(i, j - 1);
					visited[i][j - 1] = true;
					stack.push(left);
				}
			}

			else {
				visited[cur.x][cur.y] = false;
				stack.pop();
			}
		}

		return false;
	}
};