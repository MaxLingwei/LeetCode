#pragma once
#include <vector>
using namespace std;
/*
左边和上方边缘的路线只有一条
其余地方的数量是该点上方和左边数量的叠加
这是基本思路
另外遇到障碍物就直接标0
特别是左侧边缘和上方边缘如果有障碍物，那么之后的路线都是0
*/


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m, n;
		m = obstacleGrid.size();
		n = obstacleGrid[0].size();
		vector<int> a(n, 0);
		vector<vector<int>> result(m, a);

		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0)
				{
					if (j == 0)
					{
						result[i][j] = 1 - obstacleGrid[i][j];
						continue;
					}
					result[i][j] = (1 - obstacleGrid[i][j]) * result[i][j - 1];
					
				}
				else if (j == 0)
				{
					if (i == 0)
					{
						result[i][j] = 1 - obstacleGrid[i][j];
						continue;
					}
					result[i][j] = (1 - obstacleGrid[i][j]) * result[i - 1][j];
				}
				else
				{
					
					result[i][j] = (result[i - 1][j] + result[i][j - 1]) * (1 - obstacleGrid[i][j]);
				}
			}
		}
		return result[m - 1][n - 1];
	}
};