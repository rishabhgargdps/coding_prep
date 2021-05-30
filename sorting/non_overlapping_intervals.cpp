#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&v1, vector<int>&v2){
           return v1[1]<v2[1];
        });
        int end = intervals[0][1];
        int cnt=1;
        for (int i=1;i<intervals.size();i++) {
            if (end<=intervals[i][0]) {
                cnt++;
                end = intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }
};