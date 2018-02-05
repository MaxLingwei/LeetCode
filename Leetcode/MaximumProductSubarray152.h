#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int global = nums[0];
		int localMax = nums[0];
		int localMin = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			int temp = localMax;
			localMax = max(max(localMax * nums[i], localMin * nums[i]), nums[i]);
			localMin = min(min(localMin * nums[i], temp * nums[i]), nums[i]);
			global = max(localMax, global);
		}
		return global;
	}
};