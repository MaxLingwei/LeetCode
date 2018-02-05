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
�ж����������Ƿ�Գ�
���߷ֱ���������a��b��ȣ��͵ݹ��ж�a->left��b->right���Լ�a->right��b->left
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