#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};


/*
先建一棵树来保存数据，由于这里的数据不会发生改动，且知道最大个数，所以使用线性结构，这样索引能够更快
将id对应的结点视为根结点，做BFS，依次累加数据
*/

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		queue<Employee*> recorder;
		vector<Employee*> tree(2000);
		Employee* getfront;
		int sum = 0;

		if (employees.empty())
		{
			return sum;
		}
		for (int i = 0; i < employees.size(); i++)
		{
			tree[employees[i]->id] = employees[i];
		}

		recorder.push(tree[id]);
		while (!recorder.empty())
		{
			getfront = recorder.front();
			if (!getfront->subordinates.empty())
			{
				for (int j = 0; j < getfront->subordinates.size(); j++)
				{
					recorder.push(tree[getfront->subordinates[j]]);
				}
			}
			sum += getfront->importance;
			recorder.pop();
		}	
		
		return sum;
	}
};
