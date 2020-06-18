#include "Queue.h"


Queue::Queue()
{
	siz = 0;
	data = new string[siz];
}

Queue::~Queue()
{
	delete[]data;
}

void Queue::Enqueue(string elem)
{

	string* temp = new string[siz + 1];
	for (int i = 0; i < siz; i++)
	{
		temp[i] = data[i];
	}
	temp[siz] = elem;
	delete[] data;
	data = temp;
	siz++;
}

void Queue::Dequeue()
{
	if (!IsEmpty())
	{

		string* temp = new string[siz - 1];
		for (int i = 0, j = 0; i < siz; i++)
		{
			if (i != 0)
			{
				temp[j] = data[i];
				j++;
			}
		}
		delete[] data;
		data = temp;
		siz--;
	}

}

bool Queue::IsEmpty() const
{
	return siz == 0;
}

int Queue::GetCount() const
{
	return siz;
}

void Queue::Clear()
{
	delete[] data;
}

void Queue::Show() const
{
	for (int i = 0; i < siz; i++)
		cout << data[i] <<"\n";
	cout << "\n-----------------------------------\n";

}



