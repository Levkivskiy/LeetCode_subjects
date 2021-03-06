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
	
	vector<string> sorted;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		vector<string> sorted_str;
		for(int i = 0; i < strs.size(); i++)
		{
			string str = strs[i];
			sort(str.begin(), str.end());
			sorted_str.push_back(str);
		}
		for(int i = 0; i < strs.size(); i++)
		{
			if(count(sorted.begin(), sorted.end(), sorted_str.at(i)) == 0)
			{
				sorted.push_back(sorted_str.at(i));
			}
		}
		vector<vector<string>> anagram(sorted.size());
		for(int i = 0; i < strs.size(); i++)
		{
			int insert_index = 0;
			for(int j = 0; j < sorted.size(); j++)
			{
				 if(sorted[j] == sorted_str[i])
				 {
					 insert_index = j;
				 }
			}
			anagram.at(insert_index).push_back(strs[i]);
		}
		return anagram;
	}
};

int main()
{
	vector<string> ss = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution sol;
	auto res = sol.groupAnagrams(ss);
    return 0;
}

