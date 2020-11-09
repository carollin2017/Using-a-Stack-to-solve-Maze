#pragma once
#include <stack>
using namespace std;

class Location {
public: 
	int dir;
	int x, y;

	Location(int row, int col) {
		x = row;
		y = col;
		dir = 0;
	}

};