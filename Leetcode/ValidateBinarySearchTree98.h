#pragma once
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
判断一棵树是否为二叉排序树
对其进行中序遍历，如果中序遍历得到的数组是有序的，则是二叉排序树
*/
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
			if (record[i - 1] >= record[i])
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