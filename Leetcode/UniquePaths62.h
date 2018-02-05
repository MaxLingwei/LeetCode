#pragma once
#include <vector>
using namespace std;
/*
左边和上方边缘的路线只有一条
其余地方的数量是该点上方和左边数量的叠加
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
