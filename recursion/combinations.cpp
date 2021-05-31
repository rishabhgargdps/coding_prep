#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>>combinations(vector<int>&arr, int begin, int end, int k){
        if(end-begin+1<k) return {};
        if(k==0) return {{}};
        vector<vector<int>>s1 = combinations(arr, begin+1,end, k-1);
        for (auto &temp: s1) {
            temp.push_back(arr[begin]);
        }
        vector<vector<int>>s2 = combinations(arr, begin+1,end, k);
        for (const auto &temp : s2) {
            s1.push_back(temp);
        }
        return s1;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        for (int i=1; i<=n; i++) {
            arr.push_back(i);
        }
        vector<vector<int>>res = combinations(arr,0,n-1, k);
        return res;
    }
};