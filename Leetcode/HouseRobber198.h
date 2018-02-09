#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
约束：不能取连续两个元素
基本思路：维护数组value，value[i]表示到第i个元素为止可以取到的最大和
如果取到第i个元素，那么就不能取第i-1个，此时value[i] = value[i - 2] + nums[i]
如果不取第i个元素，那么肯定要取第i-1个，此时value[i] = value[i - 1]
取这两者较大的进行状态转移
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		
		vector<int> value(nums.size());
		value[0] = nums[0];
		value[1] = max(nums[0], nums[1]);
		
		for (int i = 2; i < nums.size(); i++)
		{
			value[i] = max(value[i - 2] + nums[i], value[i - 1]);
		}
		return value.back();
	}
};