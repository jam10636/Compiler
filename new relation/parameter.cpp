#include"parameter.h"
Parameter::Parameter(string x,string y)
{
	type = x;
	value = y;
}
string Parameter::tostring()
{
	return value;
}
string Parameter::gettype()
{
	return type;
}