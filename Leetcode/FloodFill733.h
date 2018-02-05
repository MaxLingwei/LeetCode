#pragma once
#include <vector>
#include <queue>

using namespace std;

/*
将连通区域填充
首先填充当前的点，然后检测四周的点，当向四周的点遍历的时候要注意不能超过边界
*/
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int origin_color = image[sr][sc];
		int col, row;

		col = image.size();
		row = image[0].size();

		if (origin_color == newColor)
		{
			return image;
		}
		
		image[sr][sc] = newColor;

		if (sr - 1 >= 0 && image[sr - 1][sc] == origin_color)
		{
			floodFill(image, sr - 1, sc, newColor);
		}
		if (sr + 1 <= col - 1 && image[sr + 1][sc] == origin_color)
		{
			floodFill(image, sr + 1, sc, newColor);
		}
		if (sc - 1 >= 0 && image[sr][sc - 1] == origin_color)
		{
			floodFill(image, sr, sc - 1, newColor);
		}
		if (sc + 1 <= row - 1 && image[sr][sc + 1] == origin_color)
		{
			floodFill(image, sr, sc + 1, newColor);
		}
		return image;
	}
};