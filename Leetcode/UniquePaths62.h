#pragma once
#include <vector>
using namespace std;
/*
��ߺ��Ϸ���Ե��·��ֻ��һ��
����ط��������Ǹõ��Ϸ�����������ĵ���
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> a(100, 0);
		vector<vector<int>> result(100, a);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 || j == 0)
				{
					result[i][j] = 1;
				}
				else
				{
					result[i][j] = result[i - 1][j] + result[i][j - 1];
				}
			}
		}
		return result[m - 1][n - 1];
	}
};
