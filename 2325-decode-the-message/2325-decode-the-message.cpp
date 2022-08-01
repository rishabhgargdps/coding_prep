class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char>m;
        int count=0;
        m[' '] = ' ';
        for(int i=0; i<key.length(); i++) {
            if(key[i] == ' ') continue;
            if(m.find(key[i]) != m.end()) continue;
            m[key[i]] = 'a'+count;
            count++;
        }
        string res = "";
        for(char c: message) {
            res += m[c];
        }
        return res;
    }
};