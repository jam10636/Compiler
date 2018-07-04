#include<iostream>
#include<string>
#include"token.h"
#include"scanner.h"
#include"parameter.h"
#include<stack>
#include"predicate.h"
#include"datalog.h"
#include"Rule.h"
#include"Expression.h"
using namespace std;
class parse
{
public:
	parse(vector<token>input);
	void beginning();
	void scheme();
	void print();
	void schemeList();
	void idList();
	void fact();
	void factList();
	void rule();
	void ruleList();
	void headPredicate();
	void predicate();
	void predicateList();
	Parameter* parameter();
	void parameterList();
	Parameter* expression();
	void operator1();
	void query();
	void querylist();
	void stringList();
	void match(tokentype token1);
	vector<Predicate>retusch();
	vector<Predicate>retufacts();
	vector<Predicate>retunquery();
	vector<RULE>returnrule();
private:
	stack<token>tokenstake;
	vector<token>tokenin1;
	datalog prog;
	Predicate pred;
	RULE rul;
	expression1* exp = NULL;
	string input;
	bool exp2 = false;
	bool check = true;
};
