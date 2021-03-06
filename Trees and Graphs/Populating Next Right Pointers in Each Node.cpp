// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include "Trees_circum.h"

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
	vector<vector<TreeLinkNode*>> levels_value;
	void calc_zigzag(TreeLinkNode* node, int level)
	{
		if (node == nullptr)
		{
			return;
		}
		if (levels_value.size() - 1 < level || levels_value.empty())
		{
			levels_value.push_back(vector<TreeLinkNode*>());
			levels_value.back().push_back(node);
		}
		else
		{
			levels_value.at(level).push_back(node);
		}
		calc_zigzag(node->left, level + 1);			
		calc_zigzag(node->right, level + 1);
	}
public:
	void connect(TreeLinkNode *root) {
		calc_zigzag(root, 0);
		for(auto level : levels_value)
		{
			for (int i = 0; i < level.size() - 1; i++)
			{
				level[i]->next = level[i + 1];
			}
		}
	}
};

int main()
{
	
	Solution sol;

	TreeLinkNode* node = new TreeLinkNode(1);
	node->left = new TreeLinkNode(2);
	node->right = new TreeLinkNode(3);
	node->left->left = new TreeLinkNode(4);
	node->left->right = new TreeLinkNode(5);
	sol.connect(node);
    return 0;
}

