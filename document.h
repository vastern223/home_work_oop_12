#pragma once
#include <iostream>
#include<string>
using namespace std;
class Document
{
private:
	string name;
	int size;
public:
	Document();
	Document(string name, int size);
	void Print()const;
	
	friend class QueueWithPriority;
	friend class Client;
};

