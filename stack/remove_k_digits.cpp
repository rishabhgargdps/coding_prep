#include <iostream>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>stk;
        for(int i=0; i<num.length();i++) {
            while(!stk.empty() && stk.top()>num[i] && k>0) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while(k>0) {
            stk.pop();
            k--;
        }
        string ans="";
        while(!stk.empty()) {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        while(ans[0]=='0') ans.erase(ans.begin());
        if(ans=="") return "0";
        return ans;
    }
};