// CS313_Zexian_Lin_hw2_Q7.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <time.h>
#include "SolveMaze.h"
#include "buildMaze.h"
#include "Location.h"
using namespace std;


int main()
{
    SolveMaze m;

    int maze[10][10] = {
        {1, 1, 0, 0, 1, 0, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1, 0, 1, 0, 0, 1},
    };
    //testing solving a given 10 * 10 maze
    if (m.isMazeReachable(maze, 10, 10, 3, 0)) {
        cout << " Path found! " << endl;
    }
    else {
        cout << "No Path Found!" << '\n';
    }
   
    //testing solving a random maze
   /* if (m.isRandomMazeReachable(10, 10, 2, 3)) {
        cout << "Path found!";
    }
    else
        cout << "No Path Found!" << '\n';*/


    

    
}

