#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort (intervals.begin(), intervals.end(), [](vector<int>v1, vector<int>v2){
           if (v1[0]==v2[0]) return v1[1]>v2[1];
           return v1[0]<v2[0];
       });
        int i=0;
       while (i!=intervals.size()-1) {
           if (intervals[i][1]>=intervals[i+1][0]) {
               intervals[i][1] = max(intervals[i][1], intervals[i+1][1]);
               auto itr = intervals.begin()+i+1;
               intervals.erase(itr);
           }
           else i++;
        }
        return intervals;
    }
};

//Alternative solution
/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort (intervals.begin(), intervals.end(), [](vector<int>v1, vector<int>v2){
           return v1[0]<v2[0];
       });
        vector<vector<int>>res;
        if (intervals.size()==0) return res;
        vector<int>prev=intervals[0];
       for(auto interval: intervals) {
           if (prev[1]>=interval[0]) {
               prev[1] = max(prev[1], interval[1]);
           }
           else {
               res.push_back(prev);
               prev=interval;
           };
        }
        res.push_back(prev);
        return res;
    }
}; 
*/