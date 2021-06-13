class Solution {
public:
    string simplifyPath(string path) {
        string temp="";
        stack<string>stk;
        stack<string>stk2;
        for(int i=0; i<path.size();i++) {
            while(path[i]!='/' && i<path.size()) {
                temp = temp+path[i];
                i++;
            }
            if(temp == "..") {
                if(!stk.empty()) stk.pop();
                temp="";
            }
            else if(temp==".") temp="";
            else if(temp.length()) {
                stk.push(temp);
                temp="";
            }
        }
        while(!stk.empty()) {
            stk2.push(stk.top());
            stk.pop();
        }
        temp="/";
        while(!stk2.empty()) {
            temp+=stk2.top()+'/';
            stk2.pop();
        }
        if(temp!="/") temp = temp.substr(0,temp.length()-1);
        return temp;
    }
};