// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;

		for (int inserting : nums)
		{
			if(map.count(inserting) != 0)
			{
				auto value = map.find(inserting);
				value->second++;
			}
			else
			{
				map.insert_or_assign(inserting, 1);
			}
		}
		vector<int> temp_vec;
		for (auto value : map)
		{
			temp_vec.push_back(value.second);
		}
		std::sort(temp_vec.begin(), temp_vec.end(), std::greater<int>());
		return vector<int>(temp_vec.begin(), temp_vec.begin() + k);
	}
};

int main()
{
	Solution sol;

	vector<int> nums = { 1, 2, 0, 1, 2, 1 };
	auto res = sol.topKFrequent(nums, 2);
	return 0;
}

