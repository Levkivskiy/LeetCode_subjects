// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <ios>
using namespace std;

class Solution {
	bool helper_search(vector<vector<char>> board, string word, int column, int row, int word_i)
	{
		if (word_i == word.size()) { return true; }
		if (board.size() - 1 < column || board[0].size() - 1 < row) { return false; }
		if (board[column][row] == word[word_i])
		{
			board[column][row] = '0';
			if (helper_search(board, word, column, row + 1, word_i + 1)) { return true; }
			if (helper_search(board, word, column + 1, row, word_i + 1)) { return true; }
			if (helper_search(board, word, column, row - 1, word_i + 1)) { return true; }
			if (helper_search(board, word, column - 1, row, word_i + 1)) { return true; }
		}
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[0].size(); j++)
			{
				if (helper_search(board, word, i, j, 0))
				{
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	
	Solution sol;
	/*
	TreeLinkNode* node = new TreeLinkNode(1);
	node->left = new TreeLinkNode(2);
	node->right = new TreeLinkNode(3);
	node->left->left = new TreeLinkNode(4);
	node->left->right = new TreeLinkNode(5);*/
	//sol.connect(node);
	vector<vector<char>> grid = {
		{'c', 'a', 'a'},
		{'a', 'a', 'a'},
		{'b', 'c', 'd'},
	};
	auto res = sol.exist(grid, "aab");
	return 0;
}

