class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        unordered_map<char, char>m;
        unordered_map<char, char>m1;
        for(string word: words) {
            if(word.length() != pattern.length()) continue;
            m.clear();
            m1.clear();
            bool match = true;
            for(int i=0; i<pattern.length(); i++) {
                if(m.find(pattern[i]) == m.end()) m[pattern[i]] = word[i];
                else if(m[pattern[i]] != word[i]) {
                    match = false;
                    break;
                }
                if(m1.find(word[i]) == m1.end()) m1[word[i]] = pattern[i];
                else if(m1[word[i]] != pattern[i]) {
                    match = false;
                    break;
                }
            }
            if(match) res.push_back(word);
        }
        return res;
    }
};