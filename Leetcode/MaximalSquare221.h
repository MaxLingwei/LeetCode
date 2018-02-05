#pragma once
#include <vector>
#include <algorithm>
using namespace std;
/*
关键：状态转移方程
如果当前元素为0，那么所处的方块大小就为0
如果当前元素为1，那么考查其left, top left_top的元素所处方块的大小
*/

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		
		int m, n;
		int top, left, max_len;
		max_len = 0;
		m = matrix.size();
		if (m == 0)
		{
			return 0;
		}
		n = matrix[0].size();
		vector<vector<int>> recorder(m, vector<int>(n, 0));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 || j == 0)
				{
					recorder[i][j] = matrix[i][j] - '0';
				}
				else if (matrix[i][j] == '0')
				{
					recorder[i][j] = 0;
				}
				else
				{
					top = recorder[i - 1][j];
					left = recorder[i][j - 1];
					if (top * left * (matrix[i][j] - '0') != 0)
					{
						recorder[i][j] = min(min(top, left), recorder[i - 1][j - 1]) + 1;
					}
					else
					{
						recorder[i][j] = matrix[i][j] - '0';
					}
				}
				max_len = max_len > recorder[i][j] ? max_len : recorder[i][j];
			}
		}
		return max_len * max_len;
	}
};