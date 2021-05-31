#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>>combination_sum(vector<int>&candidates, int begin, int end, int target) {
        //Base case
        if (target==0) return {{}};
        if (target<0) return {};
        if(begin>end) return {};
        
        //Recursive step
        vector<vector<int>>s1 = combination_sum(candidates, begin, end, target-candidates[begin]);
        for (auto &temp : s1) {
            temp.push_back(candidates[begin]);
        }
        vector<vector<int>>s2 = combination_sum(candidates, begin+1, end, target);
        for (const auto &temp : s2) {
            s1.push_back(temp);
        }
        return s1;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        return combination_sum(candidates, 0, n-1, target);
    }
};