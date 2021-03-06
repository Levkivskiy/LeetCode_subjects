// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if(intervals.empty())
		{
			return vector<Interval>();
		}
		vector<Interval> res_vec = { intervals.front() };
		for (int i = 1; i < intervals.size(); i++)
		{
			if (res_vec.back().start > intervals[i].start)
			{
				res_vec.back().start = intervals[i].start;
			}
			if (res_vec.back().end < intervals[i].start)
			{
				res_vec.push_back(intervals[i]);
			}
			else if(res_vec.back().end < intervals[i].end)
			{
				res_vec.back().end = intervals[i].end;
			}
		}
		return res_vec;
	}
};

int main()
{
	Solution sol;

	vector<Interval> nums = { Interval(1, 3), Interval(2, 6), Interval(8, 10) , Interval(15, 18) };
	vector<Interval> nums2 = { Interval(1, 4), Interval(0, 1) };
	vector<int> empty;
	auto res = sol.merge(nums);
	return 0;
}

