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

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main()
{
	vector<pair<int, int>> temp;
	int
		n,
		_,
		__,
		res = 0,
		last = 0;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> _ >> __;
		temp.push_back(make_pair(_, __));
	}

	sort(temp.begin(), temp.end(), comp);

	for (int i = 0; i < n; i++) {
		if (temp[i].first >= last) {
			last = temp[i].second;
			res++;
		}
	}

	cout << res;

	return 0;
}
