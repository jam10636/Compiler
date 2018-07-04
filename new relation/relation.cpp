#include"relation.h"
void relation::addtuple(Tuple x)
{
	tuples.insert(x);
}
void relation::addschmea(string x)
{
	schema.push_back(x);
}
relation relation::select(int x, string y)
{
	relation r;
	r.schema = schema;
	for (set<Tuple>::iterator itr = tuples.begin(); itr != tuples.end(); itr++)
	{
		Tuple t = *itr;
		if (t.at(x) == y)
		{
			r.addtuple(t);
		}
	}
	return r;
}
relation relation::selectid(int x, int y)
{
	relation r;
	r.schema = schema;
	for (set<Tuple>::iterator  itr = tuples.begin(); itr != tuples.end(); itr++)
	{
		Tuple t = *itr;
		if (t.at(x) == t.at(y))
		{
			r.addtuple(t);
		}
	}
	return r;
}
relation relation::project(vector<int>&pro)
{
	relation r;
	set<Tuple>projecttup;
	for (set<Tuple>::iterator  itr = tuples.begin(); itr != tuples.end(); itr++)
	{
		Tuple t = *itr;
		Tuple projected;
		for (int i = 0; i < pro.size(); i++)
		{
			projected.push_back(t.at(pro[i]));
		}
		r.addtuple(projected);
	}
	for (int i = 0; i < pro.size(); i++)
	{
		r.addschmea(schema[pro[i]]);
	}
	return r;
}
relation relation::rename(vector<string>name)
{
	relation r;
	r.schema = schema;
	r.tuples = tuples;
	if (schema.size() != 0)
	{

		for (int i = 0; i < name.size(); i++)
		{
			r.schema[i] = name[i];
		}
	}
	return r;
}
void relation::tostring()
{
	set<Tuple>::iterator itr = tuples.begin();
	Tuple t = *itr;
	for (int i = 0; i < tuples.size(); i++)
	{
		//cout << schema.size() << endl;
		for (int a = 0; a < schema.size(); a++)
		{
			if (a == 0)
			{
				cout << "  " << schema[a] << "=";
			}
			else
			{
				cout << " " << schema[a] << "=";
			}
			if (a != schema.size() - 1)
			{
				cout << t.at(a) << ",";
			}
			else
			{
				cout << t.at(a) << endl;

			}
		}
		if (i != tuples.size() - 1)
		{
			itr++;
			t = *itr;
		}

	}

}
vector<string> relation::getsch()
{
	return schema;
}
set<Tuple> relation::gettu()
{
	return tuples;
}
relation relation::Union(relation& y)
{
	vector<string> second = y.schema;
	relation o;
	relation r;
	r.schema = schema;
	r.tuples = tuples;
	if (schema == second)
	{
		for (set<Tuple>::iterator itr = y.tuples.begin(); itr != y.tuples.end(); itr++)
		{
			Tuple t = *itr;
			r.addtuple(t);
		}
		return r;
	}
	return o;
}
vector<string>relation::joinsche(vector<string>&y)
{
	vector<string>now = schema;
	for (int i = 0; i < y.size(); i++)
	{
		bool check1 = true;
		for (int a = 0; a < schema.size(); a++)
		{
			if (y[i] == schema[a])
			{
				check1 = false;
			}
		}
		if (check1)
		{
			now.push_back(y[i]);
		}
	}
	return now;
}