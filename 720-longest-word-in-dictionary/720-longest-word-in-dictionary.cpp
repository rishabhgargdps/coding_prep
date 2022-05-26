class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string>s;
        sort(words.begin(), words.end());
        for(string w : words) {
            if(w.length() == 1 || s.find(w.substr(0, w.length()-1)) != s.end()) {
                if(w.length() > res.length()) res = w;
                s.insert(w);
            }
        }
        return res;
    }
};