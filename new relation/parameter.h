#pragma once
#include<string>
using namespace std;
class Parameter
{
public:
	Parameter() {};
	Parameter(string type,string message);
	virtual string tostring();
	string gettype();
	~Parameter() {};
private:
	string value;
	string type;
};