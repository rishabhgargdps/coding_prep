#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>res; 
class Solution {
public:
   void combination_sum(vector<int>&candidates, int begin, int end, int target, vector<int>currSet) {
        //Base case
        if (target==0) {
            res.push_back(currSet);
            return;
        }
        if (target<0) return;
        if(begin>end) return;
        
        //Recursive step
        //don't include the first element
        combination_sum(candidates, begin+1, end, target, currSet);
        //include the first element
        currSet.push_back(candidates[begin]);
        combination_sum(candidates, begin, end, target-candidates[begin], currSet);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        res.clear();
        combination_sum(candidates, 0, n-1, target, {});
        return res;
    }
};