#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
Լ��������ȡ��������Ԫ��
����˼·��ά������value��value[i]��ʾ����i��Ԫ��Ϊֹ����ȡ��������
���ȡ����i��Ԫ�أ���ô�Ͳ���ȡ��i-1������ʱvalue[i] = value[i - 2] + nums[i]
�����ȡ��i��Ԫ�أ���ô�϶�Ҫȡ��i-1������ʱvalue[i] = value[i - 1]
ȡ�����߽ϴ�Ľ���״̬ת��
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