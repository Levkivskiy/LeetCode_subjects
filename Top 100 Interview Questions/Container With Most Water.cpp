// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0,
			right = height.size() - 1,
			max_water = 0;
		while (left < right)
		{
			max_water = std::max(max_water, std::min(height[left], height[right]) * (right - left));
			if (height[left] < height[right])
			{
				left++;
			}
			else
			{
				right--;
			}
		}
		return max_water;
	}
};
int main()
{
	Solution sol;

	vector<int> nums = { 1,8,6,2,5,4,8,3,7 };
	vector<vector<int>> nums2{{ -1 },{ -1 }};
	auto res = sol.maxArea(nums);
	return 0;
}

