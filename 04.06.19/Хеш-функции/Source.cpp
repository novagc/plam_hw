#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <numeric>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

long long times[33];

int op1(int x, int y) 
{ 
	int t = x + y;
	return t * 2 + t % 2 + t % 3 + t % 5 + t % 7 + t % 13;
}

struct Node 
{
	Node* next;
	string key;
	string value;

	Node() {
		next  = NULL;
		key   = "";
		value = "";
	}

	Node(string key, string value, Node* next = NULL) {
		this->next = next;
		this->key   = key;
		this->value = value;
	}

	~Node() {
		next = NULL;
		key = "";
		value = "";
	}
};

class Table {
	int size;

	Node** table;
public:
	Table(int size = 1024, int mode = 0) {
		this->size = size;
		
		table = new Node*[size];

		for (int i = 0; i < size; i++) {
			table[i] = NULL;
		}
	}

	~Table()
	{
		Node* cur;
		Node* next;

		for (int i = 0; i < size; i++) {
			for (cur = table[i]; cur != NULL; cur = next) {
				next = cur->next;
				delete cur;
			}
		}

		size = 0;
		cur = next = NULL;

		delete table;
	}

	void Add(string &key, string &value) {	
		int hash = CalcHash(key);

		if (table[hash] == NULL) {
			table[hash] = new Node(key, value);
		}
		else {
			Node* temp = new Node(key, value, table[hash]);
			table[hash] = temp;
		}
	}

	string* Find(string &key) {
		int hash = CalcHash(key);

		for (Node* cur = table[hash]; cur != NULL; cur = cur->next)
			if (cur->key == key)
				return &cur->value;

		return NULL;
	}

	string* Remove(string& key) {
		int hash = CalcHash(key);

		if (table[hash] != NULL) {
			string temp;

			Node* cur;
			Node* prev;

			if (table[hash]->key == key) {
				temp = table[hash]->value;
				cur = table[hash];

				table[hash] = table[hash]->next;

				delete cur;
				return &temp;
			}

			for (prev = table[hash], cur = table[hash]->next; cur != NULL; prev = cur, cur = cur->next) {
				if (cur->key == key) {
					temp = cur->value;
					prev->next = cur->next;

					delete cur;
					return &temp;
				}
			}
		}

		return NULL;
	}
	
	int CalcHash(string text) {
		return accumulate(text.begin(), text.end(), 1, op1) % size;
	}

	void Print() {
		stringstream t("");
		t << size << ".txt";

		ofstream fout(t.str());

		int min = 10e10;
		int max = 0;

		fout << "------------" << size << "------------\n";

		for (int i = 0, c = 0; i < size; i++, c = 0) {
			fout << ">> " << i << "\n";

			for (Node* cur = table[i]; cur != NULL; cur = cur->next) {
				c++;
				fout << "[ " << cur->key << " " << cur->value << " ]\n";
			}

			if (c < min)
				min = c;
			if (c > max)
				max = c;

			fout << "COUNT: " << c << '\n';
		}
		
		fout << "	MIN: " << min << '\n';
		fout << "	MAX: " << max << '\n';
		fout << "	DIF: " << max - min << "\n";

		fout << "------------" << size << "------------\n";
		fout.close();
	}
};

long long GenerateInput (int count = 10e6, int size_key = 20, int size_value = 10, string fileName = "input.txt") {
	freopen(fileName.c_str(), "w", stdout);

	cout << count << '\n';

	steady_clock::time_point begin;
	steady_clock::time_point end;

	char* temp = new char[size_key + size_value + 3];
	char* tmp  = temp + size_key + 1;

	int ran;

	temp[size_key + size_value + 1] = '\n';
	temp[size_key + size_value + 2] = '\0';

	begin = steady_clock::now();

	for (int j = 0; j < count; j++)
	{
		for (int i = 0; i < size_key; i++)
		{
			ran = rand();
			temp[i] = 'A' + 32 * (ran % 2) + ran % 26;
		}

		temp[size_key] = ' ';

		for (int i = 0; i < size_value; i++)
		{
			ran = rand();
			tmp[i] = 'A' + 32 * (ran % 2) + ran % 26;
		}

		cout << temp;
	}

	end = steady_clock::now();

	freopen("CON", "w", stdout);

	cout << "GENERATED\n";

	return duration_cast<milliseconds>(end - begin).count();
}

void Test(string** records, int count, int size, int ind) {
	Table t(size);
	string* temp;

	steady_clock::time_point begin;
	steady_clock::time_point end;
	
	begin = steady_clock::now();
	for (int i = 0; i < count; i++) {
		t.Add(records[i][0], records[i][1]);
	}
	end = steady_clock::now();

	times[ind] = duration_cast<milliseconds>(end - begin).count();

	t.Print();

	begin = steady_clock::now();
	for (int i = 0; i < count; i++) {
		temp = t.Find(records[i][0]);
	}
	end = steady_clock::now();

	times[ind + 1] = duration_cast<milliseconds>(end - begin).count();

	begin = steady_clock::now();
	for (int i = 0; i < count; i++) {
		temp = t.Remove(records[i][0]);
	}
	end = steady_clock::now();

	times[ind + 2] = duration_cast<milliseconds>(end - begin).count();

	cout << ind << " DONE!\n";
}

int main()
{
	int count;

	string temp;
	string** records;

	long long t = GenerateInput(1e5);

	freopen("input.txt", "r", stdin);

	cin >> count;
	records = new string * [count];
	
	for (int i = 0; i < count; i++) {
		records[i] = new string[2];
		
		cin >> temp;
		records[i][0] = temp;
		
		cin >> temp;
		records[i][1] = temp;
	}

	thread t1(Test, records, count, 1, 0);
	thread t2(Test, records, count, 2, 3);
	thread t3(Test, records, count, 4, 6);
	thread t4(Test, records, count, 8, 9);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	thread t5(Test, records, count, 16, 12);
	thread t6(Test, records, count, 32, 15);
	thread t7(Test, records, count, 64, 18);
	thread t8(Test, records, count, 128, 21);

	t5.join();
	t6.join();
	t7.join();
	t8.join();

	thread t9(Test, records, count, 256, 24);
	thread t10(Test, records, count, 512, 27);
	thread t11(Test, records, count, 1024, 30);

	t9.join();
	t10.join();
	t11.join();

	freopen("stats.csv", "w", stdout);

	cout << "\"Generation\";" << t << '\n';
	cout << "\"Count\";" << count << '\n';
	cout << '\n';

	cout << "Size;AddTime;FindTime;RemoveTime\n";
	
	for (int i = 0, size = 1; i < 11; i++, size *= 2) {
		cout << size << ";" << times[i * 3] << ";" << times[i * 3 + 1] << ";" << times[i * 3 + 2] << "\n";
	}

	return 0;
}
