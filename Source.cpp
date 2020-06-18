#include<iostream>
#include "QueueWithPriority.h"
#include "document.h"
#include<string>

using namespace std;

int main()
{
	QueueWithPriority test(10);
	
	Document dox1("lol", 10);
	Document dox2("lol2", 11);
	Client kli (10, "vasa");
	Client kli1(4, "dima");

	kli.Add_doc(dox1);
	kli1.Add_doc(dox2);
	test.AddWithPriority(kli);
	test.AddWithPriority(kli1);
	test.Show();
	test.ExtractElem();

	cout << endl;
	test.Show();
	test.ExtractElem();
	test.Show_statistic();
	system("pause");
	return  0;
}