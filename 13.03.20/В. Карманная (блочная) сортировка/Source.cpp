#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

void bucketSort(int* arr, int n) {
    std::vector<std::vector<int>> buckets(n / 2);
    int minElement = arr[0];
    int maxElement = arr[0];
    int numBuckets = n / 2;
    int delta;

    for (int i = 0; i < n; i++) {
        if (minElement > arr[i])
            minElement = arr[i];
        else if (maxElement < arr[i])
            maxElement = arr[i];
    }

    delta = (float(maxElement - minElement)) / numBuckets;;

    for (int i = 0, index = -1; i < n; i++) {
        index = (int)((arr[i] - minElement) / delta);
        buckets.at(index >= numBuckets ? numBuckets - 1 : index).push_back(arr[i]);
    }

    for (int i = 0; i < numBuckets; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    for (int i = 0, j = 0; i < numBuckets; i++)
        for (int k = 0; k < buckets[i].size(); k++)
            arr[j++] = buckets[i][k];
}

int main()
{
    std::ifstream inp("input.txt", std::ios::in);
    std::ofstream out("output.txt", std::ios::out);

    int n;

    inp >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        inp >> arr[i];
    }

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        out << arr[i] << ' ';

    return 0;
}
