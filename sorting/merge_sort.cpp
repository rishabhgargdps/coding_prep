#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v, int l, int mid, int r) {
    //Copy the content of left and right subarrays after mergeSort into two temp arrays;
    vector<int>temp_l(v.begin()+l,v.begin()+mid+1);
    vector<int>temp_r(v.begin()+mid+1,v.begin()+r+1);
    //merge the two sorted arrays;
    int i=0,j=0,k=l;
    while(i<temp_l.size() && j<temp_r.size()) {
        if (temp_l[i]<=temp_r[j]) v[k++] = temp_l[i++];
        else v[k++] = temp_r[j++];
    }
    while(i<temp_l.size()) {
        v[k++] = temp_l[i++];
    }
    while(j<temp_r.size()) {
        v[k++] = temp_r[j++];
    }
}

void mergeSort(vector<int>&v, int l, int r) {
    if (l<r) {
        int mid = l + (r-l)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);
        merge(v,l,mid,r);
    }
    return;
}

void print(const vector<int>&v) {
    for (int i: v) {
        cout << i << " ";
    }
}

int main() {
    vector<int>v = {1,3,5,7,9,2,8,4};
    int n = v.size();
    mergeSort(v,0,n-1);
    print(v);
    return 0;
}