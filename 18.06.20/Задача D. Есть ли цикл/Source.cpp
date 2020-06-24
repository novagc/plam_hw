#define _CRT_SECURE_NO_WARNINGS
#define ll long long

#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <stdexcept>
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
#include <random>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <regex>
#include <tuple>
#include <map>
#include <set>

using namespace std;

void DFS(bool &bad, int** mp, int* v, int n, int cur) {
	v[cur] = 1;
	for (int i = 0; i < n && !bad; i++) {
		if (mp[cur][i] == 1) {
			if (v[i] == 0)
				DFS(bad, mp, v, n, i);
			else if (v[i] == 1){
				bad = true;
				return;
			}
		}
	}
	v[cur] = 2;
}

int main()
{
	bool bad = false;

	int** mp;
	int* v;

	int res = 0;

	int n;

	cin >> n;

	v = new int[n];
	mp = new int* [n];

	for (int i = 0; i < n; i++) {
		mp[i] = new int[n];
		v[i] = 0;

		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			DFS(bad, mp, v, n, i);

			if (bad) {
				cout << 1;
				return 0;
			}
		}
	}
	
	cout << 0;
	return 0;
}
