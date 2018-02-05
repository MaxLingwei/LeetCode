#pragma once
#include <vector>
#include <algorithm>
using namespace std;
/*
result[i][j]��ʾԭ�����д�i��j����ô�����У�������Ϸ����ĳ��������ܻ�õ�������
sum[i][j]��ʾԭ�����i��j���ۼӺ�
result[i][j] = max(sum[i+1][j] - result[i+1][j] + nums[i], sum[i][j-1] - dp[i][j-1] + nums[j])
���player1��ȡֵ�ķ�Χ��i��j����player2��ȡֵ�ķ�Χ��i+1��j����i��j-1
�����е���ȡ�꣬���player1ȡ���������ڻ�����������ܺϵ�һ�룬���ʤ
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