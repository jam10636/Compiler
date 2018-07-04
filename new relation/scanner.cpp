#include"scanner.h"
void scanner::readfile(string input)
{
	infile.open(input);
	while (!infile.eof())
	{
		
		cur = infile.get();
		switch (cur) //scanning for tokens
		{
		case ',':
		{
			tokenin.push_back(token(",", line, COMMA));
			still = false;
		}
		break;
		case'.':
		{
			tokenin.push_back(token(".", line, PERIOD));
			still = false;
		}
		break;
		case '?':
		{
			tokenin.push_back(token("?", line, Q_MARK));
			still = false;
		}
		break;
		case '(':
		{
			tokenin.push_back(token("(", line, LEFT_PAREN));
			still = false;
		}
		break;
		case ')':
		{
			tokenin.push_back(token(")", line, RIGHT_PAREN));
			still = false;
		}
		break;
		case ':':
		{
			sentence = cur;
			colon();
			still = false;
		}
		break;
		case '*':
		{
			tokenin.push_back(token("*", line, MULTIPLY));
			still = false;
		}
		break;
		case '+':
		{
			tokenin.push_back(token("+", line, ADD));
			still = false;
		}
		break;
		case '#':
		{
			sentence = cur;
			comment();
			still = false;
		}
		break;
		case '\'':
		{
			sentence = cur;
			quote();
			still = false;
		}
		break;
		}
		if (isalpha(cur))
		{						
			still = false;
			sentence = cur;
			alphate();
		}
		else if (isspace(cur))
		{						//check if it is a space
			still = false;
			space();
		}
		line += lineincrease;
		lineincrease = 0;					//make up for the line increase for '\n' in comment and string
		if (still == true&&cur!=EOF)
			{								//unrecoginzable token
				string my(1, cur);
				tokenin.push_back(token(my, line, UNDEFINED));			
			}

			still = true;
	}
	tokenin.push_back(token("", eofline, MYEOF));
	infile.close();
	line = 1;
	eofline = 1;
	lineincrease = 0;
	sentence = "";
	still = true;
	print();
	//tokenin.clear();
}
void scanner::space()
{
	if (cur == '\n')
	{					//to see if line increase
		line++; 
		eofline++;
	}
}
void scanner::alphate()
{
	while (isalnum(infile.peek()))
	{
		cur = infile.get();				//to see if it is followed by digit or alphabate
		sentence += cur;
	}
	if (sentence == "Schemes")
	{
		tokenin.push_back(token("Schemes", line, SCHEMES));
	}
	else if (sentence == "Facts")
	{
		tokenin.push_back(token("Facts", line, FACTS));
	}
	else if (sentence == "Rules")
	{
		tokenin.push_back(token("Rules", line, RULES));
	}
	else if (sentence == "Queries")
	{
		tokenin.push_back(token("Queries", line, QUERIES));
	}
	else
	{
		tokenin.push_back(token(sentence, line, ID));
	}
	sentence = "";
}
void scanner::colon()
{
	if (infile.peek() == '-')   //to see if it is followed by dash
	{
		cur = infile.get();
		sentence += cur;
		tokenin.push_back(token(sentence, line, COLON_DASH));
	}
	else
	{
		tokenin.push_back(token(":", line, COLON));
	}
	sentence = "";
}
void scanner::comment()
{
	if (infile.peek() != '|')
	{
		while (infile.peek() != '\n'&&infile.peek() != EOF)		//it is like finite state machine, keep reading until the end
		{
			cur = infile.get();
			sentence += cur;
		}
		tokenin.push_back(token(sentence, line, COMMENT));
		sentence = "";
		cur = infile.get();
	}
	else if (infile.peek() == '|')			//check to see if it is block comment
	{
		cur = infile.get();
		sentence += cur;
		longcomment();
	}
}
void scanner::longcomment()
{
	bool check = true;
	while (check == true)	
	{				
		cur = infile.get();
		if (cur == '|'&&infile.peek() == '#')			//checking to see if it is the end
		{
			sentence += cur;
			cur = infile.get();
			sentence += cur;
			tokenin.push_back(token(sentence, line, COMMENT));
			check = false;
		}
		else if (cur == '\n')
		{
			if (infile.peek() == EOF)		//if reaching the end before block comment
			{
				sentence += cur;     // just added
				tokenin.push_back(token(sentence, line, UNDEFINED));
				check = false;
			}
			else
			{
				sentence += cur;
				eofline++;
				lineincrease++;
			}
		}
		else
		{
			if (cur == EOF)
			{
				tokenin.push_back(token(sentence, line, UNDEFINED));
				check = false;
			}
			else
			{
				sentence += cur;
			}
		}
	}
	sentence = "";
	}
vector<token> scanner::print()
{
	/*for (int i = 0; i < tokenin.size(); i++)
	{
		cout << "(" << tokenin[i].tostring(tokenin[i].totype) << "," << "\"" << tokenin[i].message << "\"," << tokenin[i].line << ")" << endl;
	}
	cout << "Total Tokens" << " = "<<tokenin.size()<<endl;*/
	return tokenin;
}
void scanner::quote()
{
	//make sure the case of single quote at last line with or without next eof
	bool check = true;
	while (check== true) //finite state machine. keep reading until finding the next quote
	{
		cur = infile.get();
		if (cur == '\n')
		{
			sentence += cur;
			eofline++;
			lineincrease++;
		}
		else if (cur ==EOF)
		{
			check = false;
			tokenin.push_back(token(sentence, line, UNDEFINED));
		}
		else if (cur == '\'')		//checking for apostrophy
		{
			sentence += cur;
			if (infile.peek() == '\'')
			{
				cur = infile.get();
				sentence += cur;
			}
			else
			{
				check = false;
				tokenin.push_back(token(sentence, line, STRING));
			}
		}
		else
		{
			sentence += cur;
		}
	}
	sentence = ""; 
}