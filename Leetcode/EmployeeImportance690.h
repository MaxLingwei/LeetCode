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
�Ƚ�һ�������������ݣ�������������ݲ��ᷢ���Ķ�����֪��������������ʹ�����Խṹ�����������ܹ�����
��id��Ӧ�Ľ����Ϊ����㣬��BFS�������ۼ�����
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
