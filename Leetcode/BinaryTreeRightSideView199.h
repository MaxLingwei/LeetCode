#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
		{
			return result;
		}
		queue<TreeNode*> current;
		queue<TreeNode*> next;

		next.push(root);
		
		while (!next.empty())
		{
			result.push_back(next.back()->val);
			current = next;
			queue<TreeNode*> temp;
			swap(temp, next);
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