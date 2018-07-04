//match function
//match(scheme) at the beginning
//try{}
//catch(token T/or string ){}
#include"Parse.h"
parse::parse(vector<token>input)
{
	tokenin1 = input;
	int i = 0;
	while (!tokenin1.empty())
	{
		if (tokenin1.back().type() != COMMENT)
		{
			tokenstake.push(tokenin1.back());
		}
		tokenin1.pop_back();
	}
}
void parse::beginning()
{
	try
	{
		match(SCHEMES);
		match(COLON);
		scheme();
		schemeList();
		match(FACTS);
		match(COLON);
		factList();
		match(RULES);
		match(COLON);
		ruleList();
		match(QUERIES);
		match(COLON);
		query();
		querylist();
		match(MYEOF);
	}
	catch (token comein)
	{
		cout << "Failure!\n  " << "(" << tokenstake.top().tostring(tokenstake.top().type())
			<< "," << "\"" << tokenstake.top().messageretu() << "\"," << 
				tokenstake.top().lineretu()<< ")" << endl;
		check = false;
	}
	//print();
}
void parse::print()
{
	if (check == true)
	{
		cout << "Success!" << endl;
		cout << prog.printall();
	}
	check = true;
}
void parse::match(tokentype token1)
{
	if (token1 == tokenstake.top().type())
	{
		tokenstake.pop();
	}
	else
	{
		//cout << tokenstake.top().tostring(token1);
		//cout << tokenstake.top().messageretu() << " " << tokenstake.top().lineretu() << endl;
		throw tokenstake.top();
	}
}
void parse::scheme()
{
	pred = Predicate();
	pred.addhead(tokenstake.top().messageretu()); //store the fisrt ID
	match(ID);
	match(LEFT_PAREN);
	pred.addbody(new Parameter(tokenstake.top().typere(),tokenstake.top().messageretu())); //store the whole things 
	match(ID);
	if (tokenstake.top().type() == COMMA)
	{
		idList();
	}
	match(RIGHT_PAREN);
	prog.addscheme(pred); //add things to the vector in datalog in the end it will come back here
}
void parse::schemeList()
{
	if (tokenstake.top().type() == ID)
	{
		scheme();
		schemeList();
	}
}
void parse::idList()
{
	if (tokenstake.top().type() == COMMA)
	{
		match(COMMA);
		pred.addbody(new Parameter(tokenstake.top().typere(),tokenstake.top().messageretu())); // add another ID type 
		match(ID);
		idList();
	}
}
void parse::fact()
{
	pred = Predicate();
	pred.addhead(tokenstake.top().messageretu());
	match(ID);
	match(LEFT_PAREN);
	pred.addbody(new Parameter(tokenstake.top().typere(),tokenstake.top().messageretu()));
	match(STRING);
	if (tokenstake.top().type() == COMMA)
	{
		stringList();
	}
	match(RIGHT_PAREN);
	match(PERIOD);
	prog.addfactes(pred);
}
void parse::factList()
{
	if (tokenstake.top().type() == ID)
	{
		fact();
		factList();
	}
}
void parse::rule()
{
	headPredicate();
	rul = RULE();
	rul.addhead(pred);//add headpredicate to the first line
	match(COLON_DASH);
	predicate();
	if (tokenstake.top().type() == COMMA)
	{
		predicateList();
	}
	match(PERIOD);
	prog.addrule(rul);// adding rules 
}
void parse::ruleList()
{
	if (tokenstake.top().type() == ID)
	{
		rule();
		ruleList();
	}
}
void parse::headPredicate()
{
	pred = Predicate();
	pred.addhead(tokenstake.top().messageretu());
	match(ID);
	match(LEFT_PAREN);
	pred.addbody(new Parameter(tokenstake.top().typere(), tokenstake.top().messageretu()));
	match(ID);
	if (tokenstake.top().type() == COMMA)
	{
		idList();
	}
	match(RIGHT_PAREN);

}
void parse::predicate()
{
	pred = Predicate(); //add the following predicate to the rules
	pred.addhead(tokenstake.top().messageretu());
	match(ID);
	match(LEFT_PAREN);
	pred.addbody(parameter());
	if (tokenstake.top().type() == COMMA)
	{
		parameterList();
	}
	match(RIGHT_PAREN);	
	rul.adpred(pred);
	exp = NULL;
}
void parse::predicateList()
{
	if (tokenstake.top().type() == COMMA)
	{
		match(COMMA);
		predicate();
		predicateList();
	}
}
Parameter* parse::parameter()
{
	if (tokenstake.top().type() == STRING || tokenstake.top().type() == ID)
	{
		Parameter* para = new Parameter(tokenstake.top().typere(), tokenstake.top().messageretu());
		match(tokenstake.top().type());
		return para;
	}
	else if(tokenstake.top().type()==LEFT_PAREN)
	{
		Parameter*anpara=expression();
		return anpara;
	}
	else
	{
		match(STRING);
	}
	/*if (tokenstake.top().type() == STRING)
	{
		pred.addbody(new Parameter(tokenstake.top().typere(), tokenstake.top().messageretu()));
		match(STRING);
	}
	else if (tokenstake.top().type() == ID)
	{
		pred.addbody(new Parameter(tokenstake.top().typere(), tokenstake.top().messageretu()));
		match(ID);
	}*/
	/*if (tokenstake.top().type() == STRING || tokenstake.top().type() == ID)
	{	
		if (exp2 == false)
		{
			pred.addbody(new Parameter(tokenstake.top().typere(), tokenstake.top().messageretu()));
		}
		match(tokenstake.top().type());
	}
	else if (tokenstake.top().type() == LEFT_PAREN)
	{
		exp2 = true;
		expression();
	}
	else
	{
		match(STRING);
	}*/
}
void parse::parameterList()
{
	if (tokenstake.top().type() == COMMA)
	{
		match(COMMA);
		pred.addbody(parameter());
		parameterList();
	}
}
Parameter* parse::expression()
{
	match(LEFT_PAREN);
	Parameter* newpara = parameter();
	string x = tokenstake.top().messageretu();
	operator1();
	Parameter* newpara2 = parameter();
	expression1* exp = new expression1(newpara, newpara2, x); //add expression to	
	//pred.addbody(exp);
	match(RIGHT_PAREN);
	return exp;
}
void parse::operator1()
{
	if (tokenstake.top().type() == ADD)
	{
		match(ADD);
	}
	else if (tokenstake.top().type() == MULTIPLY)
	{
		match(MULTIPLY);
	}
	else
	{
		match(ADD);
	}
}
void parse::query()
{
	pred = Predicate();
	pred.addhead(tokenstake.top().typere());
	predicate();
	match(Q_MARK);
	prog.addquery(pred);
}
void parse::querylist()
{
	if (tokenstake.top().type() == ID)
	{
		query();
		querylist();
	}
}
void parse::stringList()
{
	match(COMMA);
	pred.addbody(new Parameter(tokenstake.top().typere(), tokenstake.top().messageretu())) ; // add string to facts
	match(STRING);
	if (tokenstake.top().type() == COMMA)
	{
		stringList();
	}
}
vector<Predicate> parse::retusch()
{
	return prog.getschem();
}
vector<Predicate> parse::retufacts()
{
	return prog.getfact();
}
vector<Predicate> parse::retunquery()
{
	return prog.getquery();
}
vector<RULE> parse::returnrule()
{
	return prog.getRule();
}