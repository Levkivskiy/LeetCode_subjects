// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.empty())
		{
			return false;
		}
		if(matrix[0].empty())
		{
			return false;
		}
		if(matrix.size() == 1 && matrix[0].size() == 1)
		{
			if (matrix[0][0] == target)
			{
				return true;
			}
		}
		int column = 0,
			row = matrix[0].size() - 1;
		while(row != 0 || column != matrix.size())
		{
			if (matrix[column][row] < target)
			{
				column++;
			}
			if (column != matrix.size() && matrix[column][row] > target)
			{
				row--;
			}
			if (row == -1 || column == matrix.size())
			{
				return false;
			}
			if(matrix[column][row] == target)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution sol;

	vector<vector<int>> nums = {
		{1, 4, 7, 11, 15 },
		{2, 5, 8, 12, 19},
		{3, 6, 9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	vector<vector<int>> nums2{{ -1 },{ -1 }};
	auto res = sol.searchMatrix(nums2, -1);
	return 0;
}

