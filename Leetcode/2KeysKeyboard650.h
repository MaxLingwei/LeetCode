#pragma once
#include <vector>
#include <algorithm>
using namespace std;

/*
�ؼ�˼·��ά������ch��ch[i]��ʾ��n����ĸʱ�Ĳ�����������Ȼ
ch[0] = 0;
ch[1] = 0;
ch[2] = 2;
����֮���������Ŀ����ĸi����Ȼͨ��j����ĸ���Ʋ�ճ����������i%j=0
�Դ�Ϊ˼·������i����������j��ch[i] = min(ch[j] + i / j),ͬʱע��ch[i]�����ֵΪi
*/

class Solution {
public:
	int minSteps(int n) {
		vector<int> ch(n + 1, 0);
		vector<int> p(n);
		int min_num = n;
		ch[0] = 0;
		ch[1] = 0;
		ch[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			ch[i] = i;
			for (int j = i - 1; j > 0; j--)
			{
				if (i % j == 0)
				{
					ch[i] = min(ch[i], ch[j] + i / j);
				}
			}
		}
		return ch[n];
	}
};