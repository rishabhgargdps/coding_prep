class Solution {
public:
    string greatestLetter(string s) {
        char r='0';
        unordered_set<char>a;
        for(char c : s) {
            a.insert(c);
        }
        for(char c : s) {
            if(a.find(toupper(c)) != a.end() && a.find(tolower(c)) != a.end()) r = max(r, c);
        }
        r = toupper(r);
        string res = "";
        if(r=='0') return res;
        return res+r;
    }
};