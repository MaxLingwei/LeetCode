// Leetcode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "ConstructBinaryTreefromInorderandPostorderTraversal106.h"
#include <vector>

using namespace std;
int main()
{
	Solution test;
	vector<int> test1({9, 3, 15, 20, 7});
	vector<int> test2({9, 15, 7, 20, 3});

	test.buildTree(test1, test2);
    return 0;
}
