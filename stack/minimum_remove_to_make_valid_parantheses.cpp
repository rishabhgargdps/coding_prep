#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>stk;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='(') stk.push(i);
            else if (s[i]==')' && !stk.empty()) stk.pop();
            else if (s[i]==')' && stk.empty()) s[i]='#';
        }
        while(!stk.empty()) {
            s[stk.top()]='#';
            stk.pop();
        }
        s.erase(remove(s.begin(),s.end(),'#'),s.end());
        return s;
    }
};