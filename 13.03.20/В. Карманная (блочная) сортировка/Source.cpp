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

void sort(vector<int>& temp) {
	vector<int> f;
	vector<int> s;
	vector<int> t;

	for (int i = 0; i < temp.size(); i++)
		if (temp[i] < 0)
			f.push_back(temp[i]);
		else if (temp[i] <= 100)
			s.push_back(temp[i]);
		else
			t.push_back(temp[i]);

	sort(f.begin(), f.end());
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	int j = 0;

	for (int i = 0; i < f.size(); i++)
		temp[j++] = f[i];

	for (int i = 0; i < s.size(); i++)
		temp[j++] = s[i];

	for (int i = 0; i < t.size(); i++)
		temp[j++] = t[i];
}

int main()
{
	vector<int> temp;
	int n;
	int _;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> _;
		temp.push_back(_);
	}

	sort(temp);

	for (int i = 0; i < n; i++)
		cout << temp[i] << ' ';

	return 0;
}
