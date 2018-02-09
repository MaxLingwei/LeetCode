#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
先统计每个数字的总和，保存到一个数组，然后转化成了house rob的问题
*/
class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		vector<int> record(10000, 0);
		int min_index, max_index;
		min_index = nums[0];
		max_index = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			min_index = min(nums[i], min_index);
			max_index = max(nums[i], max_index);
			record[nums[i]] += nums[i];
		}

		vector<int> value(max_index + 1, 0);
		value[min_index] = record[min_index];
		value[min_index + 1] = max(record[min_index], record[min_index + 1]);
		for (int i = min_index + 2; i <= max_index; i++)
		{
			value[i] = max(value[i - 1], value[i - 2] + record[i]);
		}
		return value[max_index];
	}
};