#include"Expression.h"
expression1::expression1(Parameter* x, Parameter*y, string val) {
	first = x;
	second = y;
	operands = val;
}
string expression1::tostring()
{
	stringstream ss;
	ss << "(" << first->tostring() << operands << second->tostring() << ")";
	return ss.str();
}