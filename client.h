#pragma once
#include "document.h"
#include<string>
class Client
{
	string name;
	Document* documents;
	int priority;
	int size;
public:
	Client();
	Client(int priority, string name);
	void Add_doc(const Document& other);
	void  PrintAllInfo()const;
	void operator=(const Client& other);
	~Client();
	friend class QueueWithPriority;

};


