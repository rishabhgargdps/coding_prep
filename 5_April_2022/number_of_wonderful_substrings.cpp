class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int res = 0;
        unordered_set<int>s;
        int mask = 0;
        s.insert(0);
        for(int i=0; i<word.length(); i++) {
            s.insert(word[i]-'a'+1);
        }
        for(int start = 0; start < word.length(); start++) {
            mask = 0;
            for(int i=start; i<word.length(); i++) {
                mask ^= (word[i]-'a'+1);
                if(s.find(mask) != s.end()) res++;
            }
        }
        
        return res;
    }
};