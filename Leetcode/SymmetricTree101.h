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

/*
判断所给的树是否对称
两边分别遍历，如果a和b相等，就递归判断a->left和b->right，以及a->right和b->left
*/
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
		{
			return true;
		}
		return helper(root->left, root->right);
	}
	bool helper(TreeNode* left, TreeNode* right)
	{
		
		if (!left || !right)
		{
			return left == right;
		}
		return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
	}
	
};