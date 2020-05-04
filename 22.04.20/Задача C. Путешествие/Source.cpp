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

int main()
{
	int next = 0;
	int res = 0;
	
	int n;
	int k;
	int s;
	int cur;
	int _;

	cin >> n >> k;
	cin >> s;
	
	cur = next = k;

	for (int i = 0; i < s && cur < n; i++) {
		cin >> _;
		
		if (cur < _) {
			if (next < _) {
				res = -1;
				break;
			}

			res++;
			cur = next;
		}

		next = _ + k;
	}

	if (cur < n)
		if (next >= n)
			res++;
		else
			res = -1;

	cout << res;

	return 0;
}