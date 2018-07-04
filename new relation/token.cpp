#include"token.h"
string token:: tostring(tokentype type)
{
	return list[type];
}
tokentype token::type()
{
	return totype;
}
string token::messageretu()
{
	return message;
}
int token::lineretu()
{
	return line;
}
string token::typere()
{
	return list[totype];
}