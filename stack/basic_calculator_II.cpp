class Solution {
public:
    int calculate(string s) {
        stack<int>stk;
        int curr=0;
        char op ='+';
        std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
        s.erase(end_pos, s.end());
        if(s.length()==0) return 0;
        for(int i=0; i<s.length(); i++) {
            if(isdigit(s[i])) {
                curr = curr*10 + (s[i]-'0');
            }
            if(!isdigit(s[i]) || i==s.length()-1) {
                if(op=='+') {
                    stk.push(curr);
                }
                else if(op=='-') {
                    stk.push(-curr);
                }
                else if(op=='*') {
                    int temp = stk.top();
                    stk.pop();
                    stk.push(curr*temp);
                }
                else if(op=='/') {
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp/curr);
                }
                op=s[i];
                curr=0;
            }
        }
        while(!stk.empty()) {
            curr+=stk.top();
            stk.pop();
        }
        return curr;
    }
};