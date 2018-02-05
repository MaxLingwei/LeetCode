#pragma once
#include <vector>

using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> now;
		now.push_back({});
		for (int i = 0; i < nums.size(); i++)
		{
			int size_now = now.size();
			for (int j = 0; j < size_now; j++)
			{
				vector<int> temp;
				temp = now[j];
				temp.push_back(nums[i]);
				now.push_back(temp);
			}
			
			
		}
		return now;
	}
};