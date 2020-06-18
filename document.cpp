#include "document.h"

    Document::Document()
	{
		name = "no_name";
	}
	Document::Document(string name, int size) :Document()
	{
		this->name = name;
		this->size = size;
	}
	void  Document:: Print()const
	{
		cout << "Name:" << name << endl;
		cout << "size:" << size << endl;
	}

