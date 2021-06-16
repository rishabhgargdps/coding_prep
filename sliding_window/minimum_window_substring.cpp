class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        vector<int>freq(128,0);
        for(char c: t) {
            freq[c]++;
        }
        int count = 0;
        int min_length = INT_MAX;
        int end = 0;
        int begin = 0;
        for(end=0; end<s.length(); end++) {
            if(--freq[s[end]] >=0) {
                count++;
            }
            while(count == t.length()) {
                if(min_length > end-begin+1) {
                    min_length = end-begin+1;
                    res = s.substr(begin, min_length);
                }
                if(++freq[s[begin]]>0) {
                    count--;
                }
                begin++;
            }
        }
        return res;
    }
};