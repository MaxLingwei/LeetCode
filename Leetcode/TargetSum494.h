#pragma once
#include <vector>
#include <numeric>
using namespace std;
/*
设所有正数之和为sum_p, 所有负数之和的绝对值为sum_n，所有数之和为sum，则
sum_p - sum_n = S
sum_p - sum_n + sum = S + sum------------------1
而sum = sum_p + sum_n
代入1式，得
2 * sum_p = S + sum
即所有正数之和为 (S + sum) / 2;
将此先做一个判断，S > sum 或者 S + sum为奇数的直接返回0；

接着问题转换为在数组nums中哪几个数相加可以得到sum_p
这样考虑：若数组中有一个数nums[i]，且现在已知x = sum_p - nums[i]共有k种加和方式，那么从x到sum_p也有k种方式（直接x+nums[i]就可以得到sum_p）

*/


class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (S > sum)
		{
			return 0;
		}
		if ((S + sum) % 2 != 0)
		{
			return 0;
		}
		int sum_p = (S + sum) / 2;
		
		vector<int> result(sum_p + 1, 0);
		result[0] = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = sum_p; j >= nums[i]; j--)
			{
				result[j] += result[j - nums[i]];
			}
		}
		return result[sum_p];
	}
};