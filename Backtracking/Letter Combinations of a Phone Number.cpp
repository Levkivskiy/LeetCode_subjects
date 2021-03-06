// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if(digits.empty())
		{
			return vector<string>;
		}
		vector<string> res;
		vector<string> charmap = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		res.push_back("");
		for (int i = 0; i < digits.size(); i++)
		{
			vector<string> tempres;
			string chars = charmap[digits[i] - '0'];
			for (int add_i = 0; add_i < chars.size(); add_i++)
				for (int prev_numb_i = 0; prev_numb_i < res.size(); prev_numb_i++)
					tempres.push_back(res[prev_numb_i] + chars[add_i]);
			res = tempres;
		}
		return res;
	}
};

int main()
{
	
	Solution sol;	
	sol.letterCombinations("234");
	return 0;
}

