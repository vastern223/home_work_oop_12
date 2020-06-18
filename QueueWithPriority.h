#pragma once
#include <iostream>
#include <windows.h>
#include "document.h"
#include "client.h"
#include "Queue.h"
#include<string>
using namespace std;


class QueueWithPriority
{
	
	Client* data;
	int* priorities;
	int maxSize;
	int size;
	Queue stat;

public:

	QueueWithPriority(int maxSize);
	~QueueWithPriority();
	void AddWithPriority(const Client& other);
	void ExtractElem();
	Client Peek() const;
	bool IsEmpty() const;
	bool IsFull() const;
	int GetCount() const;
	void Clear();
	void Show() const;
	void Show_statistic() const;
	
};
