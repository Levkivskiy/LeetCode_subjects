// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include "Trees_circum.h"

using namespace std;

class Solution {
	vector<vector<int>> levels_value;
	void calc_zigzag(TreeNode* node, int level)
	{
		if (node == nullptr)
		{
			return;
		}
		if (levels_value.size() - 1 < level || levels_value.empty())
		{
			levels_value.push_back(vector<int>());
			levels_value.back().push_back(node->val);
		}
		else
		{
			levels_value.at(level).push_back(node->val);
		}
		if (level % 2 == 0)
		{
			calc_zigzag(node->right, level + 1);
			calc_zigzag(node->left, level + 1);
		}
		else
		{
			calc_zigzag(node->left, level + 1);
			calc_zigzag(node->right, level + 1);
		}
	}
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		
		calc_zigzag(root, 0);
		return levels_value;
	}
};

int main()
{
	
	Solution sol;

	TreeNode* node = new TreeNode(1);
	node->left = new TreeNode(2);
	node->right = new TreeNode(3);
	node->left->left = new TreeNode(4);
	node->left->right = new TreeNode(5);
	auto res = sol.zigzagLevelOrder(node);
    return 0;
}

