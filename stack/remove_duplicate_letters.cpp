#include <iostream>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last_index(26,-1);
        vector<bool>visited(26,false);
        stack<char>stk;
        string ans="";
        //last_index array to be made
        for(int i=0; i<s.length();i++) {
            last_index[s[i]-'a'] = i;
        }
        for(int i=0; i<s.length(); i++) {
            if(visited[s[i]-'a']) continue;
            while(!stk.empty() && stk.top()>s[i] && last_index[stk.top()-'a'] > i) {
                // cout << stk.top() << i << endl;
                visited[stk.top()-'a']=false;
                stk.pop();
            }
            stk.push(s[i]);
            visited[s[i]-'a']=true;
        }
        while(!stk.empty()) {
            ans=ans+stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};