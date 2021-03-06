// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* result_list = new ListNode(0);
		ListNode* resultReturn = result_list;
		int plus_one = 0;
		while(l1 != NULL && l2 != NULL)
		{
			int value = l1->val + l2->val + plus_one;
			plus_one = value >= 10 ? 1 : 0;
			auto* temp = new ListNode(value % 10);
			result_list->next = temp;
			result_list = result_list->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* add_to_end = NULL;
		if(l1 != NULL)
		{
			add_to_end = l1;
		}
		if(l2 != NULL)
		{
			add_to_end = l2;
		}
		while (add_to_end != NULL)
		{
			int value = add_to_end->val + plus_one;
			plus_one = value >= 10 ? 1 : 0;
			result_list->next = new ListNode(value % 10);
			result_list = result_list->next;
			add_to_end = add_to_end->next;
		}
		if(plus_one != 0)
		{
			result_list->next = new ListNode(plus_one);
		}

		return resultReturn->next;
	}
};


int main()
{

	Solution sol;/*
	ListNode* first = new ListNode(2);
	first->next = new ListNode(4);
	first->next->next = new ListNode(3);

	ListNode* second = new ListNode(5);
	second->next = new ListNode(6);
	second->next->next = new ListNode(4);*/
	ListNode* first = new ListNode(1);

	ListNode* second = new ListNode(9);
	second->next = new ListNode(9);
	auto res = sol.addTwoNumbers(first, second);
    return 0;
}

