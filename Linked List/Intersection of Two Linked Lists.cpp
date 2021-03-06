// LeetCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
  class Solution {
	  int find_length(ListNode* node)
	  {
		  int len = 0;
		  while (node != nullptr)
		  {
			  len++;
			  node = node->next;
		  }
		  return len;
	  }
	  ListNode* move_to_poss(ListNode* node, int len)
	  {
		  for (int i = 0; i < len; i++)
		  {
			  node = node->next;
		  }
		  return node;
	  }
  public:

	  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		  int a_length = find_length(headA);
		  int b_length = find_length(headB);
		  if (a_length != b_length)
		  {
			  if (a_length > b_length)
			  {
				  headA = move_to_poss(headA, a_length - b_length);
			  }
			  else
			  {
				  headB = move_to_poss(headB, b_length - a_length);
			  }
		  }
		  while (headA != nullptr)
		  {
			  if (headA == headB)
			  {
				  return headA;
			  }
			  headA = headA->next;
			  headB = headB->next;
		  }
		  return nullptr;
	  }
  };


int main()
{
	
	Solution sol;
	/*
	ListNode* first = new ListNode(2);
	first->next = new ListNode(4);
	first->next->next = new ListNode(3);

	ListNode* second = new ListNode(5);
	second->next = new ListNode(6);
	second->next->next = new ListNode(4);*/
	ListNode* first = new ListNode(2);
	first->next = new ListNode(4);
	first->next->next = new ListNode(3);

	ListNode* second = new ListNode(5);
	second->next = first->next->next;
	auto res = sol.getIntersectionNode (first, second);
    return 0;
}

