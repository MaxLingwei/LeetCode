#pragma once
#include<vector>
#include<algorithm>
using namespace std;


/*
基本思想：某一块island的面积等于这个island中的某一点的面积（为1）与这个点四周的面积相加，依此遍历
*/
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty())
		{
			return 0;
		}
		int max_area = 0;
		
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					max_area = max(getarea(grid, i, j), max_area);
				}
			}
		}
		return max_area;
	}
	int search(vector<vector<int>>& grid, int x, int y, int area)
	{
		int result = area;
		int height = grid.size();
		int weith = grid[0].size();

		grid[x][y] = 0;

		if (x - 1 >= 0 && grid[x - 1][y] == 1)
		{
			result = search(grid, x - 1, y, result + 1);
		}
		if (x + 1 <= height - 1 && grid[x + 1][y] == 1)
		{
			result = search(grid, x + 1, y, result + 1);
		}
		if (y - 1 >= 0 && grid[x][y - 1] == 1)
		{
			result = search(grid, x, y - 1, result + 1);
		}
		if (y + 1 <= weith - 1 && grid[x][y + 1] == 1)
		{
			result = search(grid, x, y + 1, result + 1);
		}
		return result;
	}
	int getarea(vector<vector<int>>& grid, int x, int y)
	{
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1)
		{
			grid[x][y] = 0;
			return 1 + getarea(grid, x + 1, y) + getarea(grid, x - 1, y) + getarea(grid, x, y + 1) + getarea(grid, x, y - 1);
		}
		return 0;
	}
};