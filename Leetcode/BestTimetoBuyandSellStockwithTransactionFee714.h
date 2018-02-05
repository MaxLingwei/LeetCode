#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int cash, hold;
		cash = 0;
		hold = -prices[0];

		for (int i = 0; i < prices.size(); i++)
		{
			cash = max(cash, hold + prices[i] - fee);
			hold = max(hold, cash - prices[i]);
		}
		return cash;
	}
};