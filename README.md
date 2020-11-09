# Using-a-Stack-to-solve-Maze

Use a stack to solve a maze.

***************************************************************************************************************************************************
We will need 3 classes(class Maze(), class Location(), class SolveMaze()) to solve this problem.


•	class Maze():

o	This class provides 3 methods:

	printMaze(): print out the maze for user to visualize the maze. 

	buildMaze(): The function will take 2 parameters row and col in, and randomly generate a matrix that fill with 0’s and 1’s. 
1 represents the Hall that user can go through, 0 represents wall. We return the randomly generated matrix.

	isVisited(): The function provides the
same size matrix that associated with the maze. We initialize the value in the matrix to be false, meaning u
nvisited. When we try to find a path in the maze, we use this matrix the keep track of the visited and unvisited positions.
***************************************************************************************************************************************************
•	class Location():

o	This class will provide the x coordination and y coordination for the user, which indicates the location the user is.

o	int dir: dir is initialized to be 0. 
	Whenever, we check a direction (up, down, left, right), we increment dir to indicate that how many directions we already checked.
***************************************************************************************************************************************************
•	class SolveMaze():

o	This class provide two functions:

	isRandomMazeReachable():

•	We use the parameter row and col to build a random maze and a visited matrix by calling buildMaze() and isVisited() from class Maze.

•	We assume that we always start from maze[0][0](fixed starting point) and try to find the destination(x, y) which is given in the parameter.

•	We use a stack to store Locations. Initially, we push the starting point to the stack. We will check all the direction clockwise (up, right, down, left). We push
the location into the stack each time when we try out a new path. We will also increase the dir variable of the topmost Location each time unless 
dir = 4 (meaning all directions are checked if 4 directions are available). If dir =24, we will pop the Location from the stack to track back to the path where we came from.

•	We will also use a visited matrix to keep track which Location was used in the path. While trying out the directions, we will also check if the l
ocation of the maze is a wall (0).

•	When the current location match the destination, we stop and print out the path we went through and return true;

	isMazeReachable():
•	The algorithm of this function is the same as isRandomMazeReachable() except we are given a fixed matrix (the matrix is hard-coded).
