#pragma once
/*
subarray[i][j]表示以A[i], B[j]结尾的最长公共子串的长度
状态转移方程：
subarray[i][j] = subarray[i - 1][j - 1] + 1, if A[i] == B[j];
subarray[i][j] = 0, otherwise;
在边界上，if A[i] == B[j], subarray[i][j] = 1; if A[i] != B[j], subarray[i][j] = 0;
*/
#include <vector>
using namespace std;

class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int subarray[1000][1000];
		int max_len = 0;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < B.size(); j++)
			{
				if (i == 0 || j == 0)
				{
					subarray[i][j] = A[i] == B[j] ? 1 : 0;
					continue;
				}
				if (A[i] == B[j])
				{
					subarray[i][j] = subarray[i - 1][j - 1] + 1;
					max_len = max_len > subarray[i][j] ? max_len : subarray[i][j];
				}
				else 
				{
					subarray[i][j] = 0;
				}
			}
		}
		return max_len;
	}
};