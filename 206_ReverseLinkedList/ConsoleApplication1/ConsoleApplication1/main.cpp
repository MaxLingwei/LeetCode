#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
public:
	ListNode *reverseList(ListNode *head)
	{
		stack<ListNode *> listnodestack;
		ListNode *resulthead = NULL;
		ListNode *temp = NULL;

		while (head != NULL)
		{
			listnodestack.push(head);
			head = head->next;
		}
		
		while (!listnodestack.empty())
		{
			if (resulthead == NULL)
			{
				resulthead = listnodestack.top();
				listnodestack.pop();
				temp = resulthead;
				temp->next = NULL;
			}
			else
			{
				temp->next = listnodestack.top();
				temp = temp->next;
				temp->next = NULL;
				listnodestack.pop();
			}
			
		}
		return resulthead;
	}
};