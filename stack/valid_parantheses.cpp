#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int>stk;
        for (char c: s) {
            if (c=='(' || c=='{' || c=='[') stk.push(c);
            else if (c==')' && !stk.empty() && stk.top()=='(') stk.pop();
            else if (c=='}' && !stk.empty() && stk.top()=='{') stk.pop();
            else if (c==']' && !stk.empty() && stk.top()=='[') stk.pop();
            else return 0;
        }
        if (!stk.empty()) return 0;
        return 1;
    }
};