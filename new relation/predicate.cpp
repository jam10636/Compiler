#include"predicate.h"
void Predicate::addhead(string x) //starting ID
{
	head = x;
}
void Predicate::addbody(Parameter* x) //we have the type and value now
{
	list.push_back(x);
}
vector<Parameter*> Predicate::getparar()
{
	return list;
}
string Predicate::tostring()
{
	stringstream ss;
	ss << head << "(" << list[0]->tostring();
	for (int i = 1; i < list.size(); i++)
	{
		ss << "," << list[i]->tostring();
	}
	ss << ")";
	return ss.str();
}
string Predicate::getname()
{
	return head;
}