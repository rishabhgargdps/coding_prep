#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int lomutoPartition(vector<int>& v, int l, int h)
{
    int pivot = v[h], i = l - 1;
    while (i <= h) {
        for (int j = l; j <= h-1; j++) {
            if (v[j] < pivot) {
                i++;
                swap(v[i], v[j]);
            }
        }
        swap(v[++i], v[h]);
        return i;
    }
}

void qsort(vector<int>& v, int l, int h)
{
    if (l < h) {
        int p = lomutoPartition(v, l, h);
        qsort(v, l, p - 1);
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