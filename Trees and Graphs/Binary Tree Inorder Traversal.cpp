// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode() : left(NULL), right(NULL) {}
};

void iterativePreorder(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	stack<TreeNode *> s;  // Создаем стек
	s.push(root);  // Вставляем корень в стек
	/* Извлекаем из стека один за другим все элементы.
	   Для каждого извлеченного делаем следующее
	   1) печатаем его
	   2) вставляем в стек правого! потомка
		  (Внимание! стек поменяет порядок выполнения на противоположный!)
	   3) вставляем в стек левого! потомка */
	while (s.empty() == false)
	{
		// Извлекаем вершину стека и печатаем
		TreeNode *temp = s.top();
		s.pop();
		cout << temp->val << " ";
		if (temp->right != nullptr)	
			s.push(temp->right); // Вставляем в стек правого потомка
		
		if (temp->left != nullptr)
			s.push(temp->left);  // Вставляем в стек левого потомка
			
	}
}


class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> stack;
		TreeNode* cur = root;
		vector<int>* vec = new vector<int>;
		while (cur != nullptr || !stack.empty()) {
			while (cur != nullptr) {
				stack.push(cur);
				cur = cur->left;
			}
			cur = stack.top();
			stack.pop();
			vec->push_back(cur->val);
			cur = cur->right;
		}
		return *vec;
	}
};

int main()
{
	/*
	Solution sol;
	
	ListNode* first = new ListNode(2);
	first->next = new ListNode(4);
	first->next->next = new ListNode(3);

	ListNode* second = new ListNode(5);
	second->next = new ListNode(6);
	second->next->next = new ListNode(4);
	ListNode* first = new ListNode(2);
	first->next = new ListNode(4);
	first->next->next = new ListNode(3);

	ListNode* second = new ListNode(5);
	second->next = first->next->next;
	auto res = sol.getIntersectionNode (first, second);*/
	TreeNode* node = new TreeNode(1);
	node->left = new TreeNode(2);
	node->right = new TreeNode(3);
	node->left->left = new TreeNode(4);
	node->left->right = new TreeNode(5);
	iterativePreorder(node);
    return 0;
}

