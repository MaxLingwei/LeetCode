#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
使用分治的思想
postorder数组中的最后一个元素一定是根结点
然后在inorder数组中找到这个根结点，根结点两边分别是两棵子树
关键是根结点两边子结点的数量如何确定？
左子树在inorder中开始的下标为start0,结束的下标为mid - 1，总共个数为num = mid - start0
在postorder中开始的下标为start1，结束的下标为start1 + num - 1
右子树在inorder中开始的下标为mid + 1，结束的下标为end0
在postorder中开始的下标为start1 + num(因为之前的num个数属于左子树)，结束的下标为end1 - 1
以上依据递归
*/
class Solution {
public:
	unordered_map<int, int> record;
	TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty())
		{
			return NULL;
		}
		for (int i = 0; i < inorder.size(); i++)
		{
			record[inorder[i]] = i;
		}
		int n = inorder.size();
		return helper(inorder, 0, n - 1, postorder, 0, n - 1);
	}
	TreeNode* helper(vector<int>& inorder, int start0, int end0, 
					 vector<int>& postorder, int start1, int end1)
	{
		if (start0 > end0 || start1 > end1)
		{
			return NULL;
		}

		int mid = record[postorder[end1]];
		int number = mid - start0;
		TreeNode* root = new TreeNode(postorder[end1]);

		root->left = helper(inorder, start0, mid - 1,
							postorder, start1, start1 + number - 1);
		root->right = helper(inorder, mid + 1, end0, 
							 postorder, start1 + number, end1 - 1);
		return root;
	}
};