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
	vector<vector<int>> tmp(10);

	for (int O = 10, o = 1; tmp[0].size() != temp.size(); o *= 10, O *= 10) {
		for (int i = 0; i < 10; i++)
			tmp[i].clear();

		for (int i = 0; i < temp.size(); i++) 
			tmp[abs(temp[i]) % O / o].push_back(temp[i]);

		for (int i = 0, j = 0; i < 10; i++)
			for (int k = 0; k < tmp[i].size(); k++)
				temp[j++] = tmp[i][k];
	}
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