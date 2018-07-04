//#include"relation.h"
#include"scanner.h"
#include"database.h"
#include"Parse.h"
/*void testcase1()
{
	//check union if it works
	relation r;
	relation newr;
	relation check;
	Tuple t;
	Tuple ct;
	Tuple newrt;
	r.addschmea("kevin");
	r.addschmea("tony");
	t.push_back("cs");
	t.push_back("cool");
	r.addtuple(t);
	check.addschmea("kevin");
	check.addschmea("tony"); 
	ct.push_back("cs");
	ct.push_back("dirty");
	check.addtuple(ct);
	relation x;
	x =r.Union(check);
	newr.addschmea("kevin");
	newr.addschmea("tony");
	newrt.push_back("cs");
	newrt.push_back("cool");
	newr.addtuple(newrt);
	newrt.clear();
	newrt.push_back("cs");
	newrt.push_back("dirty");
	newr.addtuple(newrt);
	
	if ((newr.getsch() == x.getsch()) && (x.gettu() == newr.gettu()))
	{
		cout<<"Success!!" << endl;
	}

}
void testcase2()
{
	// check union with mulitples tuples
	relation r;
	relation newr;
	relation check;
	Tuple t;
	Tuple ct;
	Tuple newrt;
	//
	r.addschmea("kevin");
	r.addschmea("tony");
	t.push_back("cs");
	t.push_back("sexy");
	r.addtuple(t);
	t.clear();
	t.push_back("horsefoot");
	t.push_back("camalunderwear");
	r.addtuple(t);
	check.addschmea("kevin");
	check.addschmea("tony");
	ct.push_back("cs");
	ct.push_back("wondermowen");
	check.addtuple(ct);
	ct.clear();
	ct.push_back("dirty");
	ct.push_back("dirtypants");
	check.addtuple(ct);
	relation x;
	x = r.Union(check);
	newr.addschmea("kevin");
	newr.addschmea("tony");
	newrt.push_back("cs");
	newrt.push_back("sexy");
	newr.addtuple(newrt);
	newrt.clear();
	newrt.push_back("horsefoot");
	newrt.push_back("camalunderwear");
	newr.addtuple(newrt);
	newrt.clear();
	newrt.push_back("cs");
	newrt.push_back("wondermowen");
	newr.addtuple(newrt);
	newrt.clear();
	newrt.push_back("dirty");
	newrt.push_back("dirtypants");
	newr.addtuple(newrt);

	if ((newr.getsch() == x.getsch()) && (x.gettu() == newr.gettu()))
	{
		cout << "Success!!" << endl;
	}
}
void testcase3()
{
	//checking natural joint two tuples but only one match with the others
	relation r;
	relation newr;
	relation check;
	relation check1;
	Tuple check12;
	Tuple t;
	Tuple ct;
	r.addschmea("A");
	r.addschmea("B");
	r.addschmea("C");
	t.push_back("1");
	t.push_back("2");
	t.push_back("3");
	r.addtuple(t);
	t.clear();
	t.push_back("2");
	t.push_back("3");
	t.push_back("4");
	r.addtuple(t);
	newr.addschmea("C");
	newr.addschmea("B");
	newr.addschmea("D");
	ct.push_back("3");
	ct.push_back("2");
	ct.push_back("1");
	newr.addtuple(ct);
	check=r.naturjoint(newr);
	check1.addschmea("A");
	check1.addschmea("B");
	check1.addschmea("C");
	check1.addschmea("D");
	check12.push_back("1");
	check12.push_back("2");
	check12.push_back("3");
	check12.push_back("1");
	check1.addtuple(check12);
	if ((check1.getsch() == check.getsch()) && (check1.gettu() == check.gettu()))
	{
		cout << "Success!!" << endl;
	}
}
void testcase4()
{
	//check natural joint for two tuples 
	relation r;
	relation newr;
	relation check;
	relation check1;
	Tuple check12;
	Tuple t;
	Tuple ct;
	r.addschmea("A");
	r.addschmea("B");
	r.addschmea("C");
	t.push_back("1");
	t.push_back("2");
	t.push_back("3");
	r.addtuple(t);
	t.clear();
	t.push_back("2");
	t.push_back("3");
	t.push_back("4");
	r.addtuple(t);
	newr.addschmea("B");
	newr.addschmea("C");
	ct.push_back("2");
	ct.push_back("3");
	newr.addtuple(ct);
	ct.clear();
	ct.push_back("3");
	ct.push_back("4");
	newr.addtuple(ct);
	check = r.naturjoint(newr);
	check1.addschmea("A");
	check1.addschmea("B");
	check1.addschmea("C");
	check12.push_back("1");
	check12.push_back("2");
	check12.push_back("3");
	check1.addtuple(check12);
	check12.clear();
	check12.push_back("2");
	check12.push_back("3");
	check12.push_back("4");
	check1.addtuple(check12);
	if ((check1.getsch() == check.getsch()) && (check1.gettu() == check.gettu()))
	{
		cout << "Success!!" << endl;
	}
}
void testcase5()
{ // check joint with different schema
	relation r;
	relation newr;
	relation check;
	relation check1;
	Tuple check12;
	Tuple t;
	Tuple ct;
	r.addschmea("A");
	r.addschmea("B");
	r.addschmea("C");
	t.push_back("1");
	t.push_back("2");
	t.push_back("3");
	r.addtuple(t);
	t.clear();
	t.push_back("3");
	t.push_back("4");
	t.push_back("5");
	r.addtuple(t);
	newr.addschmea("D");
	newr.addschmea("E");
	ct.push_back("4");
	ct.push_back("5");
	newr.addtuple(ct);
	check = r.naturjoint(newr);
	check1.addschmea("A");
	check1.addschmea("B");
	check1.addschmea("C");
	check1.addschmea("D");
	check1.addschmea("E");
	check12.push_back("1");
	check12.push_back("2");
	check12.push_back("3");
	check12.push_back("4");
	check12.push_back("5");
	check1.addtuple(check12);
	check12.clear();
	check12.push_back("3");
	check12.push_back("4");
	check12.push_back("5");
	check12.push_back("4");
	check12.push_back("5");
	check1.addtuple(check12);
	if ((check1.getsch() == check.getsch()) && (check1.gettu() == check.gettu()))
	{
		cout << "Success!!" << endl;
	}
}
void testcase6()
{// check for joint if same attribute but none of them match. then it will be nothign
	relation r;
	relation newr;
	relation check;
	relation check1;
	Tuple check12;
	Tuple t;
	Tuple ct;
	r.addschmea("A");
	r.addschmea("B");
	r.addschmea("C");
	t.push_back("1");
	t.push_back("2");
	t.push_back("3");
	r.addtuple(t);
	t.clear();
	t.push_back("3");
	t.push_back("4");
	t.push_back("5");
	r.addtuple(t);
	newr.addschmea("A");
	newr.addschmea("B");
	ct.push_back("7");
	ct.push_back("8");
	newr.addtuple(ct);
	check = r.naturjoint(newr);
	check1.addschmea("A");
	check1.addschmea("B");
	check1.addschmea("C");
	if ((check1.getsch() == check.getsch()) && (check1.gettu() == check.gettu()))
	{
		cout << "Success!!" << endl;
	}

}
void testcase7()
{
	//checking natrual joint with one relation with no tuples
	relation r;
	relation newr;
	relation check;
	relation check1;
	Tuple check12;
	Tuple t;
	Tuple ct;
	r.addschmea("A");
	r.addschmea("B");
	r.addschmea("C");
	t.push_back("1");
	t.push_back("2");
	t.push_back("3");
	r.addtuple(t);
	t.clear();
	t.push_back("3");
	t.push_back("4");
	t.push_back("5");
	r.addtuple(t);
	newr.addschmea("A");
	newr.addschmea("B");
	newr.addschmea("C");
	check = r.naturjoint(newr);
	check1.addschmea("A");
	check1.addschmea("B");
	check1.addschmea("C");
	if ((check1.getsch() == check.getsch()) && (check1.gettu() == check.gettu()))
	{
		cout << "Success!!" << endl;
	}
}
void testcase8()
{ //check joint with only one tuples match
	relation r;
	relation newr;
	relation check;
	relation check1;
	Tuple check12;
	Tuple t;
	Tuple ct;
	r.addschmea("A");
	r.addschmea("B");
	r.addschmea("C");
	t.push_back("1");
	t.push_back("2");
	t.push_back("3");
	r.addtuple(t);
	t.clear();
	t.push_back("3");
	t.push_back("4");
	t.push_back("5");
	r.addtuple(t);
	newr.addschmea("A");
	newr.addschmea("D");
	ct.push_back("1");
	ct.push_back("8");
	newr.addtuple(ct);
	check = r.naturjoint(newr);
	check1.addschmea("A");
	check1.addschmea("B");
	check1.addschmea("C");
	check1.addschmea("D"); 
	check12.push_back("1");
	check12.push_back("2");
	check12.push_back("3");
	check12.push_back("8");
	check1.addtuple(check12);
	if ((check1.getsch() == check.getsch()) && (check1.gettu() == check.gettu()))
	{
		cout << "Success!!" << endl;
	}
}
void testcase9()
{ // check with same attribute but different order
	relation r;
	relation newr;
	relation check;
	relation check1;
	Tuple check12;
	Tuple t;
	Tuple ct;
	r.addschmea("A");
	r.addschmea("B");
	r.addschmea("C");
	t.push_back("1");
	t.push_back("2");
	t.push_back("3");
	r.addtuple(t);
	t.clear();
	t.push_back("3");
	t.push_back("4");
	t.push_back("5");
	r.addtuple(t);
	newr.addschmea("C");
	newr.addschmea("B");
	newr.addschmea("A");
	ct.push_back("3");
	ct.push_back("2");
	ct.push_back("1");
	newr.addtuple(ct);
	check = r.naturjoint(newr);
	check1.addschmea("A");
	check1.addschmea("B");
	check1.addschmea("C");
	check12.push_back("1");
	check12.push_back("2");
	check12.push_back("3");
	check1.addtuple(check12);
	if ((check1.getsch() == check.getsch()) && (check1.gettu() == check.gettu()))
	{
		cout << "Success!!" << endl;
	}
}
void testcase11()
{ //checking union with some attributes matching 
	relation r;
	relation newr;
	relation check;
	relation check1;
	Tuple check12;
	Tuple t;
	Tuple ct;
	r.addschmea("A");
	r.addschmea("B");
	r.addschmea("C");
	t.push_back("1");
	t.push_back("2");
	t.push_back("3");
	r.addtuple(t);
	newr.addschmea("D");
	newr.addschmea("C");
	newr.addschmea("E");
	ct.push_back("2");
	ct.push_back("3");
	ct.push_back("1");
	newr.addtuple(ct);
	ct.clear();
	ct.push_back("4");
	ct.push_back("3");
	ct.push_back("2");
	newr.addtuple(ct);
	check = r.naturjoint(newr);
	check1.addschmea("A");
	check1.addschmea("B");
	check1.addschmea("C");
	check1.addschmea("D");
	check1.addschmea("E");
	check12.push_back("1");
	check12.push_back("2");
	check12.push_back("3");
	check12.push_back("2");
	check12.push_back("1");
	check1.addtuple(check12);
	check12.clear();
	check12.push_back("1");
	check12.push_back("2");
	check12.push_back("3");
	check12.push_back("4");
	check12.push_back("2");
	check1.addtuple(check12);
	if ((check1.getsch() == check.getsch()) && (check1.gettu() == check.gettu()))
	{
		cout << "Success!!" << endl;
	}
}*/

int main()
{
	scanner ss;
	ss.readfile("test.txt");
	parse aa(ss.print());
	aa.beginning();
	database dd(aa.retusch(), aa.retufacts(), aa.retunquery(), aa.returnrule());
	system("pause");
	return 0;
}
	/*
	scanner ss;
	ss.readfile(argv[1]);
	parse aa(ss.print());
	aa.beginning();
	database dd(aa.retusch(), aa.retufacts(), aa.retunquery());
	return 0;int main(int argc, char*argv[])
{
	scanner ss;
	ss.readfile(argv[1]);
	parse aa(ss.print());
	aa.beginning();
	return 0;
}

}*/
