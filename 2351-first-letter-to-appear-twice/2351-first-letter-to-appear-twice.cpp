class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char>x;
        for(char c: s) {
            if(x.find(c) != x.end()) return c;
            x.insert(c);
        }
        return 'a';
    }
};