class Solution {
public:
    int characterReplacement(string s, int k) {
        int begin = 0;
        int end = 0;
        int max_length = 0;
        vector<int>count(26,0);
        int max_count = 0;
        for(end = 0; end<s.length(); end++) {
            count[s[end]-'A']++;
            max_count = max(max_count, count[s[end]-'A']);
            while(end - begin + 1 - max_count > k) {
                count[s[begin]-'A']--;
                begin++;
            }
            max_length = max(max_length, end-begin+1);
        }
        return max_length;
    }
};