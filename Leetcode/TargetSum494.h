#pragma once
#include <vector>
#include <numeric>
using namespace std;
/*
����������֮��Ϊsum_p, ���и���֮�͵ľ���ֵΪsum_n��������֮��Ϊsum����
sum_p - sum_n = S
sum_p - sum_n + sum = S + sum------------------1
��sum = sum_p + sum_n
����1ʽ����
2 * sum_p = S + sum
����������֮��Ϊ (S + sum) / 2;
��������һ���жϣ�S > sum ���� S + sumΪ������ֱ�ӷ���0��

��������ת��Ϊ������nums���ļ�������ӿ��Եõ�sum_p
�������ǣ�����������һ����nums[i]����������֪x = sum_p - nums[i]����k�ּӺͷ�ʽ����ô��x��sum_pҲ��k�ַ�ʽ��ֱ��x+nums[i]�Ϳ��Եõ�sum_p��

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