#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Command
{
	public:
		string commandName;
};

int mai234234234()
{
	stack<int> tal;
	stack<Command> commandStack;


	tal.push(12);
	tal.push(1);
	tal.push(5);
	cout << tal.size() << endl;
	int n = tal.top();
	cout << n << endl;
	tal.pop();
	cout << tal.size() << endl;


	return 0;
}