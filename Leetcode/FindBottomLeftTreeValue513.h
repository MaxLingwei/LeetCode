#pragma once
#include <iostream>
#include <queue>

using namespace std;

/*
使用广度优先遍历
每一层的节点放入一个队列中
最后一个非空的队列的第一个元素就是最底层的最左侧元素
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