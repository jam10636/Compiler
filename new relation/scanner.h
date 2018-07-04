#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include"token.h"
#include<vector>
using namespace std;
class scanner
{
	friend class token;
public:
	scanner(){}
	~scanner(){}
	void readfile(string input); 
	void space();
	void alphate();
	void colon();
	void comment();
	void longcomment();
	void quote();
	vector<token> print();
protected:
	vector<token>tokenin;
	char cur;
	string sentence;
	int line = 1;
	int eofline = 1;
	ifstream infile;
	tokentype type;
	bool still = true; 
	int lineincrease = 0;
};
