#include"database.h"
void database::addschemes()
{
	for (int i = 0; i < sche.size(); i++)
	{
		relation r;
		string name = sche[i].getname();
		vector<Parameter*> x = sche[i].getparar();
		for (int a = 0; a< x.size(); a++)
		{
			r.addschmea(x[a]->tostring());
		}
		rel.insert({ name, r });
	}
}
void database::addfaces()
{
	for (int i = 0; i < Facs.size(); i++)
	{
		Tuple t;
		string name = Facs[i].getname();
		relation r = rel[name];
		vector<Parameter*> x = Facs[i].getparar();
		for (int a = 0; a< x.size(); a++)
		{
			t.push_back(x[a]->tostring());
		}
		r.addtuple(t);
		rel[name] = r;
	}
}
void database::querycheck()
{
	relation newr;
	//bool isid = false;
	//int now = 0;
	for (int i = 0; i < quer.size(); i++)
	{
		vector<string>count;
		vector<int>pos;
		bool isid = false;
		int now = 0;
		string name = quer[i].getname();
		relation r = rel[name];
		vector<Parameter*> x = quer[i].getparar();
		newr = r;
		for (int a = 0; a < x.size(); a++)
		{
			if (x[a]->gettype() == "ID")
			{
				isid = false;
				now = 0;
				for (int b = 0; b < count.size(); b++)
				{
					if (x[a]->tostring() == count[b])
					{
						isid = true;
						now = abc[count[b]];
					}
				}
				if (isid == true)
				{
					newr = newr.selectid(a, now);
				}
				else
				{
					count.push_back(x[a]->tostring());
					abc.insert({x[a]->tostring(),a});
					pos.push_back(a);
				}
			}
			else //it is a string
			{
				newr = newr.select(a, x[a]->tostring());
			}
		}
		newr = newr.project(pos);
		newr = newr.rename(count);
		cl.push_back(newr);
		abc.clear();
		//count.clear();
		//pos.clear();
	}
}
void database::print()
{
	for (int i = 0; i < quer.size(); i++)
	{
		cout << quer[i].tostring() << "? ";
		if (cl[i].tuples.size() != 0)
		{
			cout << "Yes(" << cl[i].tuples.size() << ")" << endl;
			cl[i].tostring();
		}
		else
		{
			cout << "No" << endl;
		}
	}

}
void database::rulescheck(int x)
{
	relation newr;
	relation r;
	//bool isid = false;
	//int now = 0;
	//for (int i = 0; i < rull.size(); i++)
	//{ 
		/*for (int o = 0; o < rull[i].list.size(); o++)
		{
			vector<string>count;
			vector<int>pos;
			bool isid = false;
			int now = 0;
			string name = rull[i].list[o].getname();
			 r = rel[name];// right here
			vector<Parameter*> x = rull[i].list[o].getparar();
			newr = r;
			for (int a = 0; a < x.size(); a++)
			{
				if (x[a]->gettype() == "ID")
				{
					isid = false;
					now = 0;
					for (int b = 0; b < count.size(); b++)
					{
						if (x[a]->tostring() == count[b])
						{
							isid = true;
							now = abc[count[b]];
						}
					}
					if (isid == true)
					{
						newr = newr.selectid(a, now);
					}
					else
					{
						count.push_back(x[a]->tostring());
						abc.insert({ x[a]->tostring(),a });
						pos.push_back(a);
					}
				}
				else //it is a string
				{
					newr = newr.select(a, x[a]->tostring());
				}
			}
			newr = newr.project(pos);
			newr = newr.rename(count);
			ru.push_back(newr);
			abc.clear();
		}*/
		rulescheck1(r, newr, rull[x]);
		newr = jointthem();
		checkhead(rull[x].pred, newr);
		//count.clear();
		//pos.clear();
}
relation database::jointthem()
{
	relation r = ru[0];
	//check if it has only one things
	for (int i = 1; i < ru.size(); i++)
	{
		r=r.naturjoint(ru[i]);
	}
	ru.clear();
	return r;
}
relation database::checkhead(Predicate& x, relation& y)
{
	vector<Parameter*>head = x.getparar();
	relation r = y;
	vector<int>check;
	for (int i = 0; i < head.size(); i++)
	{
		if (head[i]->gettype() == "ID")
		{
			for (int a = 0; a < y.schema.size();a++)
			{
				if (head[i]->tostring() == y.schema[a])
				{
					check.push_back(a);
				}
			}
		}
	}
	r = r.project(check);
	string name = x.getname();
	relation i = rel[name];
	r.schema = i.schema;
	r=r.Union(i);
	rel[name] = r;
	return r;
} 
int database::getsize()
{
	int size = 0;
	for (map<string, relation>::iterator itr = rel.begin(); itr != rel.end(); ++itr)
	{
		size += itr->second.tuples.size();
	}
	return size;
}
void database::ruleeval()
{
	int passes = 0;
	int presize = 0;
	int postsize = 0;
	cout << "Rule Evaluation" << endl;
	for (int i = 0; i < x.scc.size(); i++)
	{
		 passes = 0;
		 presize = 0;
		 postsize = 0; 
		 set<int>::iterator it = x.scc[i].begin();
		 if (x.scc[i].size() == 1&&x.checkdep(*it)==true)
		 {
			 rulescheck(*it);
			 passes = 1;
		 }
		 else
		 {
			 do
			 {
				 presize = getsize();
				 for (auto it = x.scc[i].begin(); it != x.scc[i].end(); it++)
				 {
					 rulescheck(*it);
				 }
				 passes++;
				 postsize = getsize();
				 cout << getsize() << endl;
			 } while (presize != postsize);
			 
		 }
		 cout << passes << " passes: ";
		 int num = 0;
		for (auto it = x.scc[i].begin(); it != x.scc[i].end(); it++)
		{
			if (num != x.scc[i].size()-1)
			{
				cout << "R" << *it << ",";
			}
			else
			{
				cout << "R" << *it;
			}
			num++;
		}
		cout << endl;
	}
	/*do
	{
		presize = getsize();
		rulescheck();
		passes++;
		postsize = getsize();6
	} while (presize != postsize);
	cout << "Schemes populated after " << passes << " passes through the Rules." << endl;*/
	cout << endl;
	cout << "Query Evaluation" << endl;

}
void database::rulescheck1(relation& r,relation& newr,RULE& rulll)
{
	for (int o = 0; o < rulll.list.size(); o++)
	{
		vector<string>count;
		vector<int>pos;
		bool isid = false;
		int now = 0;
		string name = rulll.list[o].getname();
		r = rel[name];// right here
		vector<Parameter*> x = rulll.list[o].getparar();
		newr = r;
		for (int a = 0; a < x.size(); a++)
		{
			if (x[a]->gettype() == "ID")
			{
				isid = false;
				now = 0;
				for (int b = 0; b < count.size(); b++)
				{
					if (x[a]->tostring() == count[b])
					{
						isid = true;
						now = abc[count[b]];
					}
				}
				if (isid == true)
				{
					newr = newr.selectid(a, now);
				}
				else
				{
					count.push_back(x[a]->tostring());
					abc.insert({ x[a]->tostring(),a });
					pos.push_back(a);
				}
			}
			else //it is a string
			{
				newr = newr.select(a, x[a]->tostring());
			}
		}
		newr = newr.project(pos);
		newr = newr.rename(count);
		ru.push_back(newr);
		abc.clear();
	}
}
void database::ruledep()
{
	for (int i = 0; i < rull.size(); i++)
	{
		dep1.push_back(rull[i].pred.getname());
	}
	for (int i = 0; i < dep1.size(); i++)
	{
		x.addnode(i);
	}
}
void database::ruledep1()
{
	for (int i = 0; i < rull.size(); i++)
	{
		for (int a = 0; a < rull[i].list.size(); a++)
		{
			string name = rull[i].list[a].getname();
			for (int o = 0; o < dep1.size(); o++)
			{
				if (name== dep1[o])
				{
					x.adddep(i, o);
				}
			}
		}
	}
	x.dfsall();
	x.sccall();
}
void database::printdep()
{
	cout << "Dependency Graph" << endl;
	x.print();
}