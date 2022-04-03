class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0, l = pref.length();
        for(string word: words) {
            if(word.substr(0, l) == pref) res++;
        }
        return res;
    }
};