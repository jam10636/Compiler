#pragma once
#include"predicate.h"
#include"Rule.h"
#include<vector>
#include<set>
class datalog
{
public:
	datalog() {};
	~datalog() {};
	void addscheme(Predicate pred);
	void addfactes(Predicate pred);
	void addquery(Predicate pred);
	void addrule(RULE ru);
	void addomain(vector<Parameter*>para);
	string toscheme();
	string tofact();
	string torule();
	string toquery();
	string todomain();
	string printall();
	vector<Predicate> getschem();
	vector<Predicate> getfact();
	vector<Predicate> getquery();
	vector<RULE> getRule();
private:
	vector<Predicate>Schemes;
	vector<Predicate>Facts;
	vector<Predicate>Querys;
	vector<RULE>rules;
	set<string>domain;
};