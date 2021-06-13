#include <iostream>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>stk;
        string temp = "";
        for(int i=0; i<logs.size(); i++) {
            temp = logs[i];
            if(temp!="../" && temp!="./") {
                stk.push(temp);
            }
            else if(temp == "../" && !stk.empty()) stk.pop();
        }
        return stk.size();
    }
};