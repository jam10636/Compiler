#pragma once
#include"predicate.h"
#include<vector>
using namespace std;
class RULE
{
public:
	RULE() {};
	~RULE() {};
	void addhead(Predicate x);
	void adpred(Predicate x);	
	string tostring();
//private:
	Predicate pred;
	vector<Predicate> list;
};