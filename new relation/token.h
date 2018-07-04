#pragma once
#include<string>
#include<iostream>
#include<string>
#include<map>
using namespace std;
enum tokentype
{
	COMMA,
	PERIOD,
	Q_MARK,
	LEFT_PAREN,
	RIGHT_PAREN,
	COLON,
	COLON_DASH,
	MULTIPLY,
	ADD,
	SCHEMES,
	FACTS,
	RULES,
	QUERIES,
	ID,
	STRING,
	COMMENT,
	WHITESPACE,
	UNDEFINED,
	MYEOF
};
class token
{
	friend class scanner;
public:
	token(string message1, int line1, tokentype type)
	{
		totype = type;
		line = line1;
		message = message1;
	}
	string tostring(tokentype);
	tokentype type();
	string messageretu();
	string typere();
	int lineretu();
private:
	string message;
	int line = 0;
	tokentype totype;
	map<tokentype, string> list{ { COMMA, "COMMA" },{ PERIOD, "PERIOD" },
	{ Q_MARK, "Q_MARK" },{ LEFT_PAREN, "LEFT_PAREN" },{ RIGHT_PAREN, "RIGHT_PAREN" },
	{ COLON, "COLON" },{ COLON_DASH, "COLON_DASH" },{ MULTIPLY, "MULTIPLY" },{ ADD, "ADD" },
	{ SCHEMES, "SCHEMES" },{ FACTS, "FACTS" },{ RULES, "RULES" },{ QUERIES, "QUERIES" },{ ID, "ID" },
	{ STRING, "STRING" },{ COMMENT, "COMMENT" },
	{ WHITESPACE, "WHITESPACE" },{ UNDEFINED, "UNDEFINED" },{ MYEOF, "EOF" } };
	
};
