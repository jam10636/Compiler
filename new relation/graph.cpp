#include"graph.h"
void graph::addnode(int x)
{
	node i;
	node u;
	thng.insert({ x,i });
	reverse.insert({ x,u});
}
void graph::adddep(int x,int y)
{
	node i = thng[x];
	node rev = reverse[y];
	i.edges.insert(y);
	rev.edges.insert(x);
	thng[x] = i;
	reverse[y] = rev;
}
void graph::print()
{
	for (int i = 0; i < thng.size(); i++)
	{
		cout <<"R"<< i << ":";
		int pa = 0;
		for (auto it = thng[i].edges.begin(); it != thng[i].edges.end(); it++)
		{	
			if (pa != thng[i].edges.size()-1)
			{
				cout << "R" << *it << ",";
			}
			else
			{
				cout << "R" << *it;
			}
				pa++;
		}
		cout << endl;
	}
	cout << endl;
	/*for (int i = 0; i < reverse.size(); i++)
	{
		cout << i << ": ";
		for (auto it = reverse[i].edges.begin(); it != reverse[i].edges.end(); it++)
		{
			cout << *it << ", ";
		}
		cout << endl;
	}
	int u = path.size();
	for (int i = 0; i < u; i++)
	{
		cout << path.top();
		path.pop();
	}*/

}
void graph::dfs(int in)
{
	node& n = reverse[in];
	n.visited = true;
	for (auto it = n.edges.begin(); it != n.edges.end(); it++)
	{
		if (reverse[*it].visited == false)
		{
			dfs(*it);
		}
	}
	path.push(in);
}
void graph::dfsall()
{
	for (int i = 0; i < reverse.size(); i++)
	{
		if (reverse[i].visited == false)
		{
			dfs(i);
		}
	}
}
void graph::sccall()
{
	int x = path.size();
	dup = path;
	for (int i = 0; i < x;i++)
	{
		if (thng[path.top()].visited == false)
		{
			sccid.insert(path.top());
			sccfunc(path.top());
			scc.push_back(sccid);
			sccid.clear();
		}
		path.pop();
	}
}
void graph::sccfunc(int id)
{
	node& n = thng[id];
	n.visited = true;
	for (auto it = n.edges.begin(); it != n.edges.end(); it++)
	{
		if (thng[*it].visited == false)
		{
			sccid.insert(*it);
			sccfunc(*it);
		}
	}
}
void graph::printsta()
{
	for (int i = 0; i < scc.size(); i++)
	{
		cout << "{ ";
		for (auto it = scc[i].begin(); it != scc[i].end(); it++)
		{
			cout << *it << ",";
		}
		cout << "}" << endl;
	}
}
vector<set<int>> graph::getscc()
{
	return scc;
}
stack<int> graph::pathre()
{
	return dup;
}
bool graph::checkdep(int x)
{
	bool che = true;
	for (auto it = thng[x].edges.begin(); it != thng[x].edges.end(); it++)
	{
		if (*it == x)
		{
			che = false;
		}
	}
	return che;
}