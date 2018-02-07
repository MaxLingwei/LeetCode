#pragma once
#include<vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
	int helper(vector<int>& nums, int start, int end)
	{
		if (start == end)
		{
			return start;
		}
		if (start + 1 == end)
		{
			return nums[start] > nums[end] ? start : end;
		}
		int mid = (start + end) / 2;

		if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
		{
			return mid;
		}
		else if (nums[mid] < nums[mid + 1])
		{
			return helper(nums, mid + 1, end);
		}
		else if (nums[mid] < nums[mid - 1])
		{
			return helper(nums, start, mid - 1);
		}
	
	}
};