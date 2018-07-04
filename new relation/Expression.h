#pragma once
#include"parameter.h"
#include<sstream>
#include<iostream>
class expression1 : public Parameter
{
public:
	expression1(Parameter* x, Parameter* y, string opera);
	virtual string tostring();
private:
	Parameter* first = NULL;
	Parameter* second = NULL;
	string operands;
};