#include <iostream>
#include <string>
#include <queue>
#include <ctime>
#include <Windows.h>

using namespace std;

class Patient
{
	time_t arrivedInQueue;
	int queueNo;
public:
	Patient(int queueNo)
	{
		this->queueNo = queueNo;
		arrivedInQueue = time(NULL);
	}
	int GetQueueNo()
	{
		return queueNo;
	}
	int SecondsInQueue()
	{
		return time(NULL) - arrivedInQueue;
	}

};


int main()
{
	SetConsoleOutputCP(1252);
	int queueNo = 1;
	string commando;
	queue<Patient> theQueue;
	while (1)
	{
		cout << "Antal i kön " << theQueue.size() << endl;
		cout << "1. Stoppa in en ny patient i väntekön" << endl;
		cout << "2. Ropa in nästa patient" << endl;
		getline(cin, commando);
		if (commando == "1")
		{
			Patient p(queueNo);
			theQueue.push(p);
			queueNo++;
		}
		if (commando == "2")
		{
			Patient p = theQueue.front();
			cout << "Ny patient ! Nr " << p.GetQueueNo() << endl;
			cout << "Patienten: Jag har väntat hela " << p.SecondsInQueue() << " sekunder...vad f-n får jag för skattepengarna" << endl;
			theQueue.pop();
		}
	}
	return 0;
}


