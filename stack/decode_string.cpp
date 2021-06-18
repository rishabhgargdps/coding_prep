class Solution {
public:
    string decodeString(string s) {
        string res="";
        stack<int>count;
        stack<string>stk;
        int i=0;
        while(i<s.length()) {
            if(isdigit(s[i])) {
                int value = 0;
                while(isdigit(s[i])) {
                    value*=10;
                    value+=(s[i]-'0');
                    i++;
                }
                count.push(value);
            }
            else if(s[i]=='[') {
                stk.push(res);
                res="";
                i++;
            }
            else if(s[i]==']') {
                string temp = stk.top();
                stk.pop();
                int counts = count.top();
                count.pop();
                for(int j=0; j<counts; j++) {
                    temp+=res;
                }
                res = temp;
                i++;
            }
            else {
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};