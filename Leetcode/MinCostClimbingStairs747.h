#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		if (cost.size() < 2)
			return min(cost[0], cost[1]);
		int pre = cost[0];
		int cur = cost[1];
		for (int i = 2; i < cost.size(); i++)
		{
			int temp = cur;
			cur = min(pre, temp) + cost[i];
			pre = temp;
		}
		return min(pre, cur);
	}

};