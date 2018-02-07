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
ʹ�÷��ε�˼��
postorder�����е����һ��Ԫ��һ���Ǹ����
Ȼ����inorder�������ҵ��������㣬��������߷ֱ�����������
�ؼ��Ǹ���������ӽ����������ȷ����
��������inorder�п�ʼ���±�Ϊstart0,�������±�Ϊmid - 1���ܹ�����Ϊnum = mid - start0
��postorder�п�ʼ���±�Ϊstart1���������±�Ϊstart1 + num - 1
��������inorder�п�ʼ���±�Ϊmid + 1���������±�Ϊend0
��postorder�п�ʼ���±�Ϊstart1 + num(��Ϊ֮ǰ��num��������������)���������±�Ϊend1 - 1
�������ݵݹ�
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