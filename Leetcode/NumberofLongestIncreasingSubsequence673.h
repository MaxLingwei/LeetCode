#pragma once
/*
recorder[i]表示以第i个元素结尾的子序列中最长子序列的长度
max_num[i]表示以第i个元素结尾的子序列中最长子序列的个数
e.x.	{1, 3, 5, 4, 7}
recorder 1, 2, 3, 3, 4
max_num  1, 1, 1, 1, 2
*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> recorder(nums.size(), 1);
		vector<int> max_num(nums.size(), 1);
		int times = 0;
		int max_len = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
				{
					if (recorder[j] + 1 > recorder[i])
					{
						recorder[i] = recorder[j] + 1;
						max_num[i] = max_num[j];
					}
					else if (recorder[j] + 1 == recorder[i])
					{
						max_num[i] += max_num[j];
					}
				}
			}
			
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (recorder[i] > max_len)
			{
				max_len = recorder[i];
				times = max_num[i];
			}
			else if (recorder[i] == max_len)
			{
				times += max_num[i];
			}
		}
		return times;
	}
};