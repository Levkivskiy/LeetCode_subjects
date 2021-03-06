// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
using namespace std;

class Solution {
public:
	int static lengthOfLongestSubstring(string s) {
		int max_sub_len = 0;
		string sub_string = "";
		int last_i = 0;
		for (int i = 0; i < s.length(); i++)
		{
			char str = s.at(i);
			if (sub_string.find(str) == string::npos) {
				sub_string += str;
			}
			else
			{
				if(max_sub_len < sub_string.length())
				{
					max_sub_len = sub_string.length();
				}
				last_i++;
				i = last_i - 1;
				sub_string = "";
			}
		}
		return max_sub_len > sub_string.length() ? max_sub_len : sub_string.length();
	}
};

int main()
{
	string ss = "abcabcbb";
	int len = Solution::lengthOfLongestSubstring(ss);
    return 0;
}

