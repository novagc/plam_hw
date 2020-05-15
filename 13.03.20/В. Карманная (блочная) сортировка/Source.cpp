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

void bucketSort(vector<int>& array) {
    int n = array.size();

    vector<vector<int>> buckets(n / 2 + 1);
    int minElement = array[0];
    int maxElement = array[0];
    int numBuckets = n / 2;
    int range;

    for (int i = 0; i < n; i++) {
        minElement = min(minElement, array[i]);
        maxElement = max(maxElement, array[i]);
    }

    range = maxElement - minElement + 1;

    for (int i = 0, index = -1; i < n; i++) {
        index = int(array[i] * numBuckets / range);
        buckets[index].push_back(array[i]);
    }

    for (int i = 0; i < numBuckets; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    for (int i = 0, j = 0; i < numBuckets; i++)
        for (int k = 0; k < buckets[i].size(); k++)
            array[j++] = buckets[i][k];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> temp;
    int n;
    int _;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> _;
        temp.push_back(_);
    }

    bucketSort(temp);

    for (int i = 0; i < n; i++)
        cout << temp[i] << ' ';

    return 0;
}
