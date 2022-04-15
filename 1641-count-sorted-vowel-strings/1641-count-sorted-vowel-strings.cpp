class Solution {
public:
    vector<char>ch = {'a', 'e', 'i', 'o', 'u'};
    int count(int length, char last_char) {
        //Base case
        if(length == 0) return 1;
        int temp = 0;
        for(char c : ch) {
            if(last_char >= c) temp += count(length-1, c);
        }
        return temp;
    }
    int countVowelStrings(int n) {
        int res = 0;
        for(char c : ch) {
            res += count(n-1, c);
        }
        return res;
    }
};