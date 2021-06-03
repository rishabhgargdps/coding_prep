#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>stk;
        int i=0,j=0;
        while(i<popped.size() && j<pushed.size()) {
            if (!stk.empty() && stk.top()==popped[i]) {
                stk.pop();
                i++;
            }
            else {
                stk.push(pushed[j]);
                j++;
            }
        }
        while(i<popped.size()) {
            if(stk.top()==popped[i]) {
                stk.pop();
                i++;
            }
            else break;
        }
        if(stk.empty()) return true;
        return false;
    }
};