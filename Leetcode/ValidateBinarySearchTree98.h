#pragma once
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root)
		{
			return true;
		}

		searchtree(root);
		for (int i = 1; i < record.size(); i++)
		{
			if (record[i - 1] > record[i])
			{
				return false;
			}
		}
		return true;
	}
	vector<int> record;
	void searchtree(TreeNode* root)
	{
		
		if (root->left)
		{
			searchtree(root->left);
		}
		record.push_back(root->val);
		if (root->right)
		{
			searchtree(root->right);
		}
	}
};