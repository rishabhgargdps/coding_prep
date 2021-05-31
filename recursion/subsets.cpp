#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate_subsets(vector<int>&nums, int l, int h) {
        //Base case
        if(l==h) return {{},{nums[h]}};
        
        //Recursive step
        vector<vector<int>>s1 = generate_subsets(nums, l+1, h);
        vector<vector<int>>res = s1;
        for (int i=0;i<s1.size();i++) {
            vector<int>temp = s1[i];
            temp.push_back(nums[l]);
            res.push_back(temp);
        }
        return res;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        res = generate_subsets(nums, 0, n-1);
        return res;
    }
};