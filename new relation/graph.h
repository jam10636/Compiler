#pragma once
#include"node.h"
#include<iostream>
using namespace std;
class graph
{
public:
	map<int, node>thng;
	map<int, node>reverse;
	stack<int>path;
	vector<set<int>>scc;
	void addnode(int x);
	void adddep (int x,int y);
	void dfs(int ind);
	void sccfunc(int id);
	void sccall();
	void dfsall();
	void print();
	void printsta();
	stack<int> pathre();
	stack<int>dup;
	vector <set<int>>getscc();
	set<int>sccid;
	bool checkdep(int x);
};