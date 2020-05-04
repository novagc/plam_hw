#define _CRT_SECURE_NO_WARNINGS
#define ll long long

#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <regex>
#include <map>
#include <set>

using namespace std;

class BinHeap
{
private:
	vector<int> list;

	void Up(int index);
	void Down(int index);

public:
	BinHeap();
	BinHeap(vector<int> arr);

	void Add(int value);

	void PrintArray();
	void PrintHeap();

	int Size();

	int DeleteMin();
	int Min();

};

BinHeap::BinHeap()
{

}

BinHeap::BinHeap(vector<int> arr)
{
	for (int x : arr)
		Add(x);
}

void BinHeap::Add(int value)
{
	list.push_back(value);
	Up(list.size() - 1);
}

int BinHeap::Size()
{
	return list.size();
}

int BinHeap::DeleteMin()
{
	int temp = list[0];

	list[0] = list[list.size() - 1];
	list.pop_back();

	Down(0);
	return temp;
}

int BinHeap::Min()
{
	return list[0];
}

void BinHeap::Up(int index)
{
	if (index == 0)
		return;

	int parent = (index - 1) / 2;

	if (list[index] < list[parent])
	{
		swap(list[index], list[parent]);
		Up(parent);
	}
}

void BinHeap::Down(int index)
{
	int child = index * 2 + 1;

	if (child >= list.size())
		return;

	if (child + 1 < list.size() && (list[index] <= list[child] || list[child] > list[child + 1]))
		child++;

	if (list[index] > list[child])
	{
		swap(list[index], list[child]);
		Down(child);
	}
}

void BinHeap::PrintArray()
{
	cout << "[ ";
	for (int x : list)
		cout << x << ' ';
	cout << ']';
}

void BinHeap::PrintHeap()
{
	for (int i = 0, count = 1, step = 1; i < list.size(); i++, count--)
	{
		if (count == 0)
		{
			cout << '\n';
			count = (step *= 2);
		}

		cout << list[i] << ' ';
	}
}

int main()
{
	BinHeap temp;
	int n;
	int _;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> _;
		temp.Add(_);
	}

	while (temp.Size() > 0) {
		cout << temp.DeleteMin() << ' ';
	}

	return 0;
}