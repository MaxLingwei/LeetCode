#pragma once
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
����һ����������鹹��ƽ��Ķ���������
ʹ�õݹ�
ȡ�м��Ԫ����Ϊ��root����ߵ�һ�������root->left���ұߵ�һ���root->right���Դ˼����ݹ�
��������ֻ������Ԫ��ʱ��rootȡһ��, root->leftȡһ���������ݹ�
��������ֻ��һ��Ԫ��ʱ��rootȡһ���������ݹ�
tips��������ʱ��ʹ�õ��������±����
*/
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		TreeNode* result = NULL;
		if (nums.size() >= 3)
		{
			int mid = nums.size() / 2;
			result = new TreeNode(nums[mid]);
			vector<int> left(nums.begin(), nums.begin() + mid);
			vector<int> right(nums.begin() + mid + 1, nums.end());
			result->left = sortedArrayToBST(left);
			result->right = sortedArrayToBST(right);
		}
		else if (nums.size() == 2)
		{
			result = new TreeNode(nums[1]);
			result->left = new TreeNode(nums[0]);
		}
		else if (nums.size() == 1)
		{
			result = new TreeNode(nums[0]);
		}
		return result;
	}
};