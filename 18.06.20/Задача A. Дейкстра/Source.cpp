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

const int INF = 1000000000;

int main() {
	int n;
	cin >> n;

	int s;
	cin >> s;
	s--;

	int f;
	cin >> f;
	f--;

	vector<vector<pair<int, int>>> g(n);
	vector<int> d(n, INF), p(n);

	d[s] = 0;
	vector<bool> u(n);

	for (int i = 0, temp; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (i != j && temp != -1) {
				g[i].push_back(make_pair(j, temp));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;

		if (d[v] == INF)
			break;

		u[v] = true;

		for (int j = 0; j < g[v].size(); j++) {
			int to = g[v][j].first;
			int len = g[v][j].second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}

	if (d[f] == INF) {
		cout << -1;
	}
	else {
		cout << d[f];
	}
}
