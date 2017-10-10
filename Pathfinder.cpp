#include "Pathfinder.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

	//Part 1-----------------------------------------------------------------------------------
	/*
	* toString
	*
	* Returns a string representation of the current maze. Returns a maze of all 1s if no maze
	* has yet been generated or imported.
	*
	* A valid string representation of a maze consists only of 125 1s and 0s (each separated
	* by spaces) arranged in five 5x5 grids (each separated by newlines) with no trailing newline. A valid maze must
	* also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
	*
	* Cell (0, 0, 0) is represented by the first number in the string representation of the
	* maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
	* number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
	* sixth number. Increasing in z means moving downward to a new grid, meaning cell
	* (0, 0, 1) is the twenty-sixth cell in the maze. Cell (4, 4, 4) is represented by the last number.
	*
	* Returns:		string
	*				A single string representing the current maze
	*/
	string Pathfinder::toString() const
  {
		stringstream s;
		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				for (int k = 0; k <= 4; k++)
				{
						s << maze[i][j][k] << " ";
				}
				s << endl;
			}
			if (i < 4)
			{
				s << endl;
			}
		}
		maze[0][0][0] << 1;
		maze[4][4][4] << 1;
		return s.str();
  }

	/*
	* createRandomMaze
	*
	* Generates a random maze and stores it as the current maze.
	*
	* The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
	* in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
	* solvable or unsolvable, and this method should be able to produce both kinds of mazes.
	*/
	void Pathfinder::createRandomMaze()
	{
		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				for (int k = 0; k <= 4; k++)
				{
					maze[i][j][k] = rand() % 2; //runs 125 times
				}
			}
		}
		maze[0][0][0] << 1;
		maze[4][4][4] << 1;
		return;
	}

	//-----------------------------------------------------------------------------------------

	//Part 2-----------------------------------------------------------------------------------
	/*
	* importMaze
	*
	* Reads in a maze from a file with the given file name and stores it as the current maze.
	* Does nothing if the file does not exist or if the file's data does not represent a valid
	* maze.
	*
	* The file's contents must be of the format described above to be considered valid.
	*
	* Parameter:	file_name
	*				The name of the file containing a maze
	* Returns:		bool
	*				True if the maze is imported correctly; false otherwise
	*/
	bool Pathfinder::importMaze(string file_name)
	{
		int tempMaze[5][5][5];

		ifstream amazing;
		amazing.open(file_name);

		for (int x = 0; x <= 4; x++)
		{
			for (int y = 0; y <= 4; y++)
			{
				for (int z = 0; z <= 4; z++)
				{
					string temp1;
					amazing >> temp1;
					//cout << temp1 << endl;
					if (temp1 != "1" && temp1 != "0" && temp1 != " ")
					{
						return false;
					}
					tempMaze[x][y][z] = stoi(temp1);
				}
			}
		}

		if (tempMaze[0][0][0] == 1 && tempMaze[4][4][4] == 1)
		{
			for (int a = 0; a <= 4; a++)
			{
				for (int b = 0; b <= 4; b++)
				{
					for (int c = 0; c <= 4; c++)
					{
						maze[a][b][c] = tempMaze[a][b][c];
					}
				}
			}
		}
		return maze;
	}

	//-----------------------------------------------------------------------------------------

	//Part 3-----------------------------------------------------------------------------------
	/*
	* solveMaze
	*
	* Attempts to solve the current maze and returns a solution if one is found.
	*
	* A solution to a maze is a list of coordinates for the path from the entrance to the exit
	* (or an empty vector if no solution is found). This list cannot contain duplicates, and
	* any two consecutive coordinates in the list can only differ by 1 for only one
	* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
	* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
	* where x, y, and z are the integer coordinates of a cell.
	*
	* Understand that most mazes will contain multiple solutions
	*
	* Returns:		vector<string>
	*				A solution to the current maze, or an empty vector if none exists
	*/
	vector<string> Pathfinder::solveMaze()
	{
		vector<string> dummy;
		return dummy;
	}
