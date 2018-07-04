#pragma once
#include"parameter.h"
#include<sstream>
#include<vector>
using namespace std;
class Predicate
{
public:
	Predicate() {};
	~Predicate() {};
	void addhead(string x);
	void addbody(Parameter* x);
	vector<Parameter*> getparar();
	string tostring();
	string getname();
private:
	string head;
	vector<Parameter*>list;
};