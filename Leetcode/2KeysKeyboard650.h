#pragma once
#include <vector>
#include <algorithm>
using namespace std;

/*
关键思路：维护数组ch，ch[i]表示有n个字母时的操作次数，显然
ch[0] = 0;
ch[1] = 0;
ch[2] = 2;
对于之后任意的数目的字母i，必然通过j个字母复制并粘贴而来，且i%j=0
以此为思路，遍历i的所有因数j，ch[i] = min(ch[j] + i / j),同时注意ch[i]的最大值为i
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