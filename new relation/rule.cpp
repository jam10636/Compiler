#include"Rule.h"
void RULE::addhead(Predicate x)
{
	pred = x;
}
void RULE::adpred(Predicate x)
{
	list.push_back(x);
}
string RULE::tostring()
{
	stringstream ss;
	ss << pred.tostring();
	ss << " :- " << list[0].tostring();
	for ( int i = 1; i<list.size(); i++)
	{
		ss << "," << list[i].tostring();
	}
	return ss.str();
}