#pragma once
#include "PathfinderInterface.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pathfinder :
	public PathfinderInterface
{

public:
	int maze[5][5][5];
	Pathfinder() {
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; j < 5; j++)
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
};
