#pragma once
#include <iostream>
#include <queue>

using namespace std;

/*
ʹ�ù�����ȱ���
ÿһ��Ľڵ����һ��������
���һ���ǿյĶ��еĵ�һ��Ԫ�ؾ�����ײ�������Ԫ��
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		int result;
		queue<TreeNode*> current;
		queue<TreeNode*> next;
		current.push(root);
		next = current;
		while (!next.empty())
		{
			current = next;
			result = current.front()->val;
			queue<TreeNode*> next;
			
			while (!current.empty())
			{
				if (current.front()->left)
				{
					next.push(current.front()->left);
				}
				if (current.front()->right)
				{
					next.push(current.front()->right);
				}
				current.pop();
			}
		}
		return result;
	}
};