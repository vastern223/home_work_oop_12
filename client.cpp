#include "client.h"


Client::Client() : documents(nullptr), priority(5), size(0), name("no_nome") {}

Client::Client(int priority, string name) : Client()
{
	if (priority > 0 && priority <= 5)
	this->priority = priority;
	documents = new Document[size];
	this->name = name;
}

void Client::Add_doc(const Document& other)
{
	Document* new_doc = new Document[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_doc[i] = documents[i];
	}
	new_doc[size] = other;
	delete[] documents;
	documents = new_doc;
	size++;
}

void Client::PrintAllInfo()const
{
	cout << "Name: " << name << endl;
	cout << "Documents: " << size << endl;
	cout << "Prioriti" << priority << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ") " << documents[i].name << endl;
	}
}

void Client:: operator=(const Client& other)
{
	this->name = other.name;
	this->priority = other.priority;
	this->size = other.size;
	documents = new Document[size];
	for (int i = 0; i < size; i++)
	{
		documents[i] = other.documents[i];
	}
}

Client:: ~Client()
{
	if(documents!=nullptr)
	delete[] documents;
}
