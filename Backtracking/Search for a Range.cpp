// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if(nums.size() == 0)
		{
			return vector<int> {-1 ,-1};
		}
		int find_i = binary_search_ind(nums, 0, nums.size() - 1, target);
		if (find_i == -1)
		{
			return vector<int> {-1, -1};
		}
		int right_pos = find_i;
		int left_pos = find_i;
		for(int i = left_pos - 1; i >= 0; i--)
		{
			if (nums[i] != nums[find_i])
			{
				break;
			}
			left_pos--;
		}
		for (int i = right_pos + 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[find_i])
			{
				break;
			}
			right_pos++;
		}
		return vector<int> {left_pos, right_pos};
	}
	int binary_search_ind(vector<int> nums, int left, int right, int target)
	{
		if(right < left)
		{
			return -1;
		}
		int mid = (left + right) / 2;
		if(target == nums[mid])
		{
			return mid;
		}
		else if(target > nums[mid])
		{
			return binary_search_ind(nums, mid + 1, right, target);
		}
		else
		{
			return binary_search_ind(nums, left, mid - 1, target);
		}
	}
};

int main()
{
	Solution sol;

	vector<int> nums = {5,7,7,8,8,10};
	vector<int> nums1 = { -1};

	vector<int> empty;
	auto res = sol.searchRange(nums, 0);
	return 0;
}

