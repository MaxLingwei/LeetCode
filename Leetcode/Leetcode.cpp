// Leetcode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "FloodFill733.h"
#include <vector>

using namespace std;
int main()
{
	Solution test;
	vector<vector<int>> testcase;
	testcase.push_back({0, 0, 0});
	testcase.push_back({ 0, 0, 0 });
	
	test.floodFill(testcase, 0, 0, 2);
    return 0;
}

