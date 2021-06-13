#include <iostream>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>stk;
        string temp1, temp2,temp3;
        for(int i=0; i<tokens.size();i++) {
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") {
                stk.push(tokens[i]);
            }
            else {
                temp2 = stk.top();
                stk.pop();
                temp1 = stk.top();
                stk.pop();
                if(tokens[i]=="+") temp3 = to_string(stoi(temp1)+stoi(temp2));
                else if(tokens[i]=="-") temp3 = to_string(stoi(temp1)-stoi(temp2));
                else if(tokens[i]=="*") temp3 = to_string(stoi(temp1)*stoi(temp2));
                else if(tokens[i]=="/") temp3 = to_string(stoi(temp1)/stoi(temp2));
                stk.push(temp3);
            }
        }
        return stoi(stk.top());
    }
};