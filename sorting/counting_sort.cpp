//in this we count the frequency of characters within a limited range and simply return the required
//number of elements
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> counting_sort(vector<int>&v){
    map<int, int> freq;
    for (int i=0; i<v.size();i++) {
        freq[v[i]]++;
    }
    int count = 0;
    for (auto x : freq) {
        for (int j = 0; j<x.second; j++) {
            v[count++] = x.first;
        }
    }
    return v;
}

int main() {
    vector<int>v={1,2,1,3,6,5,4,4};
    v = counting_sort(v);
    for (int i =0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}