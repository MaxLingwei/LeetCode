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
根据一个有序的数组构造平衡的二叉排序树
使用递归
取中间的元素作为根root，左边的一半数组给root->left，右边的一半给root->right，以此继续递归
当数组中只有两个元素时，root取一个, root->left取一个，结束递归
当数组中只有一个元素时，root取一个，结束递归
tips：索引的时候使用迭代器比下标更快
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