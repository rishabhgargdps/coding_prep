//partition the array into sorted and unsorted parts and insert elements from unsorted part 
//into the sorted part
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x=y;
    y=temp;
}

void insertion_sort(vector<int>&v) {
    int n = v.size();
    for (int i=0; i<n-1; i++) {
        int temp = v[i+1];
        int k=0;
        for (int j=i; j>=0; j--) {
            v[j+1]=v[j];
            k=j;
            if (v[j] < v[i+1]) {
                break;
            }
        }
        v[k]=temp;
        swap(v[k],v[k+1]);
    }
}

int main() {
    vector<int>v={1,4,2,3};
    insertion_sort(v);
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}