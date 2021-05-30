//find the ith maximum element and swap with the first element
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x=y;
    y=temp;
}

void selection_sort(vector<int>&v) {
    int n = v.size();
    for(int i=0; i<n-1;i++) {
        for (int j=i; j<n; j++) {
            if (v[i] > v[j]) {
                swap(v[i],v[j]);
            }
        }
    }
}

int main() {
    vector<int>v={1,4,2,3};
    selection_sort(v);
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}