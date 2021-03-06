// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int min = INT_MAX, sec_min = INT_MAX;
		for (int x : nums) {
			if (x <= min) {
				min = x;          
			}
			else if (x <= sec_min) {
				sec_min = x;          
			}
			else {             
				return true;      
			}
		}
		return false;
	}
};


int main()
{

	vector<int> incres = { 10, 5, 6, 1, 3, 2, 9};
	Solution sol;
	auto res = sol.increasingTriplet(incres);
    return 0;
}

