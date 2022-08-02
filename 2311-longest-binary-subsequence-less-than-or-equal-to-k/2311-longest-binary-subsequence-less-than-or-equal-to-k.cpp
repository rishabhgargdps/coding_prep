class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count0 = 0, count1=0;
        for(char c: s) {
            if(c == '0') count0++;
        }
        long long num=0;
        int two=0;
        int flag = 0;
        for(int i=s.length()-1; i>=0; i--) {
            flag++;
            if(flag > 33) break;
            if(s[i] == '1') {
                if(num >= k) break;
                num += pow(2, two);
                // cout << num << endl;
                if(num > k) break;
                count1++;
            }
            two++;
        }
        return count0+count1;
    }
};