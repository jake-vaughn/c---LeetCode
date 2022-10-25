#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *ret = new ListNode();
		ListNode *curr = ret;
		int sum = 0;
		int carry = 0;

		while (l1 != nullptr || l2 != nullptr || carry != 0)
		{
			if (l1 != nullptr)
			{
				sum += (*l1).val;
				l1 = (*l1).next;
			}
			if (l2 != nullptr)
			{
				sum += (*l2).val;
				l2 = (*l2).next;
			}
			sum += carry;
			if (sum >= 10)
			{
				sum -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			curr->next = new ListNode(sum);
			sum = 0;
			curr = curr->next;
		}
		return ret->next;
	}
};

int main()
{
	ListNode t1(3);
	ListNode t2(4, &t1);
	ListNode l1(2, &t2);

	ListNode t3(4);
	ListNode t4(6, &t3);
	ListNode l2(5, &t4);

	Solution solution;
	ListNode *sol = solution.addTwoNumbers(&l1, &l2);

	while (sol)
	{
		cout << (*sol).val;
		sol = (*sol).next;
	}
	return 0;
}