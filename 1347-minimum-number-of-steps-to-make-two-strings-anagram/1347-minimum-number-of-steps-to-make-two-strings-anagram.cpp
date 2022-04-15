class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int, int>m;
        for(char c : t) m[c]++;
        for(char c : s) m[c]--;
        int res = 0;
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            if(itr->second > 0) res += abs(itr->second);
        }
        return res;
    }
};