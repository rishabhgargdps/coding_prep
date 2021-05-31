// this is an implementation using the Hoare's partition where the first element is taken as the pivot
// considered the best among Lomuto and Naive partitions.
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int hoarePartition(vector<int>& v, int l, int h)
{
    int pivot = v[l];
    int i = l - 1, j = h + 1;
    while (true) {
        do {
            i++;
        } while (v[i] < pivot);
        do {
            j--;
        } while (v[j] > pivot);
        if (i >= j)
            return j;
        swap(v[i], v[j]);
    }
}

void qsort(vector<int>& v, int l, int h)
{
    if (l < h) {
        int p = hoarePartition(v, l, h);
        qsort(v, l, p);
        qsort(v, p + 1, h);
    }
}

void print(const vector<int>& v)
{
    for (int i : v)
        cout << v[i] << " ";
}

int main()
{
    vector<int> v = { 1, 5, 4, 2 };
    qsort(v, 0, v.size() - 1);
    print(v);
    return 0;
}