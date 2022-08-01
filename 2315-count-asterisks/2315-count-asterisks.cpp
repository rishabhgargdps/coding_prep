class Solution {
public:
    int countAsterisks(string s) {
        int res = 0;
        bool flag = true;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '*' && flag) res++;
            else if(s[i] == '|') flag = !flag;
        }
        return res;
    }
};