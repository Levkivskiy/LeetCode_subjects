// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
private:
	int size;
	void mark_land(int i, int j, char num_land)
	{
		if(i < my_grid.size() && j < my_grid.at(0).size())
		{
			if (my_grid.at(i).at(j) == '1')
			{
				my_grid[i][j] = num_land;
				mark_land(i, j + 1, num_land);
				mark_land(i + 1, j, num_land);
				mark_land(i, j - 1, num_land);
				mark_land(i - 1, j, num_land);
			}
		}
	}
	vector<vector<char>> my_grid;
public:
	int numIslands(vector<vector<char>>& grid) {
		my_grid = grid;
		size = 0;
		char num_land = '2';
		for(int i = 0; i < my_grid.size(); i++)
		{
			for(int j = 0; j < my_grid.back().size(); j++)
			{
				if(my_grid.at(i).at(j) == '1')
				{
					size++;
					mark_land(i, j, num_land++);
				}
			}
		}
		return size;
	}
};

int main()
{
	Solution sol;

	vector<vector<char>> grid = {
		{'0', '1', '1'},
		{'0', '1', '0'},
		{'0', '1', '0'},
		{'1', '1', '1'},
	};
	sol.numIslands(grid);
	return 0;
}

