#include<iostream>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int>stk1;
        stack<int>stk2;
        for(char c :s) {
            if(c!='#') stk1.push(c);
            else if(c=='#' && !stk1.empty()) stk1.pop();
        }
        for(char c:t) {
            if(c!='#') stk2.push(c);
            else if(c=='#' && !stk2.empty()) stk2.pop();
        }
        while(!stk1.empty() && !stk2.empty()) {
            if(stk1.top()==stk2.top()) {
                stk1.pop();
                stk2.pop();
            }
            else break;
        }
        return (stk1.empty() && stk2.empty());
    }
};