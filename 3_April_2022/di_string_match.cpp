class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>res(s.length() + 1);
        int low = 0, high = s.length();
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'I') res[i] = low++;
            else res[i] = high--;
        }
        res[s.length()] = high;
        return res;
    }
};