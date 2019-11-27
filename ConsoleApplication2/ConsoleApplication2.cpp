// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Queue
//- lab Skapa en stack för Commands.
//Detta är kommandon i tex Word
//
//Skicka in en Command(string name)
//(detta kan vara tex "Cut", "Insert table" etc etc
//	Nu kan vi "Undo"


#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Cmd
{
public:
	string CommandName;
};

class StringStack
{
	vector<string> strings;
public:
	void Push(string s)
	{
		strings.push_back(s);
	}
	void Pop()
	{
		strings.pop_back();
	}
	bool IsEmpty()
	{
		//return strings.size() == 0;
		return strings.empty();
	}
	string Top()
	{
		return strings.back();
	}
};


string Reverse(string s)
{
	stack<char> stacken;
	for (char ch : s)
	{
		stacken.push(ch);
	}
	string sNew;
	while (!stacken.empty())
	{
		sNew = sNew + stacken.top();
		stacken.pop();
	}
	return sNew;
}

bool IsBalanced(string code)
{
	stack<char> stacken;
	int num = 0;
	for (char ch : code)
	{
		if (ch == '(' || ch == '{')
			stacken.push(ch);
		if (ch == ')' || ch == '}')
		{
			char start = stacken.top();
			if ( ( ch == ')' && start != '(' ) || (ch == '}' && start != '{'))
			{
				cout << "error tecken " << num << endl;
				return false;
			}
			stacken.pop();
		}
		num++;
	}
	return stacken.empty();
}


int ma4535in()
{
	string code = "if (stack.empty()) "
"	{                                    "
"		cout << stack.top() << endl;  "
"		continue;    "
"	}";
	cout << IsBalanced(code) << endl;

	StringStack sta;
	sta.Push("Hello");
	sta.Push("There");
	string saa = sta.Top();
	sta.Pop();
	saa = sta.Top();
	sta.Pop();


	cout << Reverse("Stefan") << endl;

	stack<string> stack;
	string commando;
	string jn;
	while (1)
	{
		cout << "Ange kommando, tex Cut, Insert table etc etc eller Undo" << endl;
		getline(cin, commando);
		if (commando == "Undo")
		{
			if (stack.empty())
			{
				cout << "Nothing to undo" << endl;
				continue;
			}
			string s = stack.top();
			cout << "Vill du undoa " << s << "? J/N?" << endl;
			getline(cin, jn);
			if (jn == "J")
			{
				stack.pop(); 
			}
		}
		else
		{
			stack.push(commando);
		}
	}
	return 0;
}

