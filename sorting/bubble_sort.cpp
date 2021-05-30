//swap adjacent elements so that the ith maximum integer in the vector gets accumulated at the end 
//in the ith iteration
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x=y;
    y=temp;
}

void bubble_sort(vector<int>&v) {
    int n = v.size();
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

int main() {
    vector<int>v={1,4,2,3};
    bubble_sort(v);
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}