#pragma once
#include "PathfinderInterface.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pathfinder :
	public PathfinderInterface
{
private:
	vector<string> P;

public:
	int maze[5][5][5];

	Pathfinder() {
		for (int k = 0; k < 5; k++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int i = 0; i < 5; i++)
				{
					maze[i][j][k] = 1;
				}
			}
		}
	}
	~Pathfinder() {}
	string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
	bool findPath(int x, int y, int z);
};
