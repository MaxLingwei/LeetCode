#pragma once
#include <vector>
#include <algorithm>
using namespace std;
/*
result[i][j]表示原数组中从i到j的这么多数中，按照游戏规则，某个玩家所能获得的最大分数
sum[i][j]表示原数组从i到j的累加和
result[i][j] = max(sum[i+1][j] - result[i+1][j] + nums[i], sum[i][j-1] - dp[i][j-1] + nums[j])
如果player1能取值的范围是i到j，则player2能取值的范围是i+1到j或者i到j-1
当所有的数取完，如果player1取到的数大于或等于所有数总合的一半，则获胜
*/

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int result[21][21];
		int sum[21];
		sum[0] = nums[0];
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			result[i][i] = nums[i];
			if (i > 0)
			{
				sum[i] = sum[i - 1] + nums[i];
			}
		}
		
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j + i < n; j++)
			{
				result[j][j + i] = max(sum[j + i] - sum[j] + nums[j] - result[j + 1][j + i], sum[j + i]- sum[j] + nums[j] - result[j][j + i - 1]);
			}
		}
		return result[0][n-1] * 2 >= sum[n - 1];
	}
};