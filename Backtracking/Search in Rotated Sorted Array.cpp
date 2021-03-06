// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) 
	{
		return binary_search_ind(nums, 0, nums.size() - 1, target);
	}
	int binary_search_ind(vector<int> nums, int left, int right, int target)
	{
		if (right < left)
		{
			return -1;
		}
		int mid = (left + right) / 2;
		if (target == nums[mid]){
			return mid; 
		}
		if (nums[left] == target){
			return left;
		}
		if (nums[right] == target){
			return right;
		}
		if (nums[left] < target && nums[mid] > target) {
			return binary_search_ind(nums, left, mid - 1, target);
		}
		if (nums[mid] < target && nums[right] > target) {
			return binary_search_ind(nums, mid + 1, right, target);
		}
		if (nums[mid] > nums[right]) {
			return binary_search_ind(nums, mid + 1, right, target);
		}				
		return binary_search_ind(nums, left, mid - 1, target);
	}
};

int main()
{
	Solution sol;

	vector<int> nums = { 4,5,6,7,0,1,2 };
	vector<int> nums2 = { 4,5,6,7,0,1,2};
	vector<int> nums3 = { 5, 1};
	vector<int> empty;
	auto res = sol.search(nums3, 0);
	return 0;
}

