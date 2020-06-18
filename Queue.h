#pragma once
#include <iostream>
#include<string>
using namespace std;



class Queue
{
	string* data;
	int siz;

public:

	Queue();
	void Enqueue(string elem);
	void Dequeue();
	bool IsEmpty() const;
	int GetCount() const;
	void Clear();
	void Show() const;
	~Queue();
	friend class QueueWithPriority;
};