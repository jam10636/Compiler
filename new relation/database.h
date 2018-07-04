#pragma once
#include"datalog.h"
#include"predicate.h"
#include"relation.h"
#include<map>
#include"graph.h"
using namespace std;
class database
{
public:
	database(vector<Predicate>sche1, vector<Predicate>facs1, vector<Predicate>quer1,vector<RULE>rulee)
	{
		sche = sche1;
		Facs = facs1;
		quer = quer1;
		rull = rulee;
		addschemes();
		addfaces();
		ruledep();
		ruledep1();
		printdep();
		ruleeval();
		querycheck();
		print();
	}
	void addschemes();
	void addfaces();
	void querycheck();
	void rulescheck(int x);
	void rulescheck1(relation& r,relation& newr,RULE& rulle);
	relation jointthem();
	relation checkhead(Predicate& x, relation& r);
	void print();
	int getsize();
	void ruleeval();
	void ruledep();
	void ruledep1();
	void printdep();
private:
	//vector<string>count;
	//vector<int>pos;
	vector<Predicate>sche;
	vector<Predicate>Facs;
	vector<Predicate>quer;
	vector<RULE>rull;
	map<string, relation> rel;
	vector<relation>cl;
	vector<relation>ru;
	map<string,int>abc;
	map<string, int>dep;
	vector<string>dep1;
	graph x;
};