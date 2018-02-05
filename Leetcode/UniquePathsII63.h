#pragma once
#include <vector>
using namespace std;
/*
��ߺ��Ϸ���Ե��·��ֻ��һ��
����ط��������Ǹõ��Ϸ�����������ĵ���
���ǻ���˼·
���������ϰ����ֱ�ӱ�0
�ر�������Ե���Ϸ���Ե������ϰ����ô֮���·�߶���0
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