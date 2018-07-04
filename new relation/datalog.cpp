#include"datalog.h"
void datalog::addscheme(Predicate x)
{
	Schemes.push_back(x);
}
void datalog::addfactes(Predicate x)
{
	Facts.push_back(x);
	addomain(x.getparar()); //add domain
}
void datalog::addquery(Predicate x)
{
	Querys.push_back(x);
}
void datalog::addrule(RULE ru)
{
	rules.push_back(ru);
}
void datalog::addomain(vector<Parameter*>input)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i]->gettype() == "STRING") //add only string
		{
			domain.insert(input[i]->tostring());
		}
	}
}
string datalog::toscheme()
{
	stringstream ss;
	ss << "Schemes(" << Schemes.size() << "):" << "\n";
	for (int i = 0; i < Schemes.size(); i++)
	{
		ss << "  " << Schemes[i].tostring() << "\n";
	}
	return ss.str();
}
string datalog::tofact()
{
	stringstream ss;
	ss << "Facts(" << Facts.size() << "):" << "\n";
	for (int i = 0; i < Facts.size(); i++)
	{
		ss <<"  "<< Facts[i].tostring() << ".\n";
	}
	return ss.str();
}
string datalog::torule()
{
	stringstream ss;
	ss << "Rules(" << rules.size() << "):" << "\n";
	for (int i = 0; i < rules.size(); i++)
	{
		ss <<"  "<< rules[i].tostring() << ".\n";
	}
	return ss.str();
}
string datalog::toquery()
{
	stringstream ss;
	ss << "Queries(" << Querys.size() << "):" << "\n";
	for (int i = 0; i < Querys.size(); i++)
	{
		ss <<"  "<< Querys[i].tostring() << "?\n";
	}
	return ss.str();
}
string datalog::todomain()
{
	stringstream ss;
	ss << "Domain(" << domain.size() << "):" << "\n";
	set<string>::iterator itr;
	for (itr = domain.begin(); itr != domain.end(); itr++)
		ss << "  " << (*itr) << "\n";
	return ss.str();
}
string datalog::printall()
{
	stringstream ss;
	ss << toscheme();
	ss << tofact();
	ss << torule();
	ss << toquery();
	ss << todomain();
	return ss.str();
}
vector<Predicate> datalog::getschem()
{
	return Schemes;
}
vector<Predicate> datalog::getfact()
{
	return Facts;
}
vector<Predicate> datalog::getquery()
{
	return Querys;
}
vector<RULE> datalog::getRule()
{
	return rules;
}