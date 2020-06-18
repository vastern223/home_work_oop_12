#include "QueueWithPriority.h"


QueueWithPriority::QueueWithPriority(int maxSize)
{

	this->maxSize = maxSize;
	data = new Client[maxSize];
	priorities = new int[maxSize];
	size = 0;
}

QueueWithPriority::~QueueWithPriority()
{
	delete[]data;
	delete[]priorities;
}

void QueueWithPriority::AddWithPriority(const Client& other)
{
	if (!IsFull())
	{
		data[size] = other;
		priorities[size] = other.priority;
		++size;

		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (priorities[j] > priorities[j + 1]) {
					swap(data[j + 1], data[j]);
					swap(priorities[j + 1], priorities[j]);
				}
			}
		}
	}

}

void QueueWithPriority::ExtractElem()
{
	if (!IsEmpty())
	{

		SYSTEMTIME st;
		GetSystemTime(&st);
		string time_doc;
		int str = 0;

		time_doc += "Time :";
		str = st.wHour;
		time_doc += to_string(str);
		str = st.wMinute;
		time_doc += ":";
		time_doc += to_string(str);
		str = st.wSecond;
		time_doc += ":";
		time_doc += to_string(str);
		time_doc += "  name :";
		time_doc += data[0].name;

		stat.Enqueue(time_doc);


		for (int i = 0; i < size; i++)
		{
			data[i] = data[i + 1];
			priorities[i] = priorities[i + 1];
		}
		--size;
	}
}

Client QueueWithPriority::Peek() const
{
	if (!IsEmpty())
	{
		return data[0];
	}

}

bool QueueWithPriority::IsEmpty() const
{
	return size == 0;
}

bool QueueWithPriority::IsFull() const
{
	return size == maxSize;
}

int QueueWithPriority::GetCount() const
{
	return size;
}

void QueueWithPriority::Clear()
{
	size = 0;
}


void QueueWithPriority::Show() const
{

	for (int i = 0; i < size; i++)
	{
		data[i].PrintAllInfo();
		cout << endl;
	}


}

void QueueWithPriority::Show_statistic() const
{
	stat.Show();
}
