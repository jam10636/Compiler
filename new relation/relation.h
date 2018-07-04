//schema tuple 
//make sure string has single quote 
//vector of string of schemea 
//vector of string of tuple 
//inherit of vecotr of string tupe:public vector<string>
/*
relation 
{ scheme a
set<tuple>
selet(x(colum)and  "value")
{
new relation 
pass in the same schema
for(eachtupe)
{
if x==a
{
add tuple
}
else
{
continue
}
return a relation
{
}
project(vector<int>clumb number
{
new schema
new tuple
}
another selcetion function for ID(x,y)
rename (schema)
{
rename schema 
}
original 
answer
call func
chekc new vs answer
print pass/fail
//
add to vecotr
select id
select 
project
rename
*/
#include"tuple.h"
#include<set>
#include"predicate.h"
#include<iostream>
#include<map>
using namespace std;
class relation
{
public:
	set<Tuple>gettu();
	vector<string>getsch();
	relation select(int col,string input);
	relation selectid(int x,int y);
	relation project(vector<int>&pro);
	void addtuple(Tuple x);
	void addschmea(string x);
	relation rename(vector<string>name);
	set<Tuple> tuples;
	relation Union(relation& y);
	vector<string>joinsche(vector<string>&y);
	inline Tuple relation::jointup(vector<int>&left, vector<int>&right, Tuple& x, Tuple& y)
	{
		Tuple u = x;
		for (int i = 0; i < y.size(); i++)
		{
			bool check = true;
			for (int a = 0; a < right.size(); a++)
			{
				if (i == right[a])
				{
					check = false;
				}
			}
			if (check == true)
			{
				u.push_back(y.at(i));
			}
		}
		return u;//here
	}
	inline relation relation::checktuple(vector<int>&left, vector<int>&right, relation& z)
	{
		relation r;
		Tuple t;
		for (set<Tuple>::iterator itr = tuples.begin(); itr != tuples.end(); itr++)
		{
			for (set<Tuple>::iterator itr1 = z.tuples.begin(); itr1 != z.tuples.end(); itr1++)
			{
				bool same = true;
				Tuple now = *itr;
				Tuple now1 = *itr1;
				for (int i = 0; i < left.size(); i++)
				{
					if (now.at(left[i]) != now1.at(right[i]))
					{
						same = false;
					}
				}
				if (same == true)
				{
					t = jointup(left, right, now, now1);
					r.addtuple(t);
				}
			}
		}
		return r;//here
	}
	inline relation relation::naturjoint(relation& y)
	{
		vector<string>yscheme = y.schema;
		vector<int>left;
		relation r;
		/*if (x.tuples.size() == 0 || y.tuples.size() == 0)
		{
		r.schema = r.joinsche(xscheme, yscheme);
		return r;
		}*/
		vector<int>right;
		//change for
		int c = schema.size();
		int b = yscheme.size();
		for (int i = 0; i < c; i++)
		{
			for (int a = 0; a < b; a++)
			{
				if (schema[i] == yscheme[a])
				{
					left.push_back(i);
					right.push_back(a);
				}
			}
		}
		r = checktuple(left, right, y);
		r.schema = joinsche(yscheme);
		return r;//here

	}
	vector<string>schema;
	void tostring();

};