#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> computeLPS(string s) {
        int m = s.length();
        vector<int>lps(m,0);
        int i=1,j=0;
        for(i=1;i<m;i++) {
            j = lps[i-1];
            while(j>0 && s[i]!=s[j]) {
                j = lps[j-1];
            }
            if(s[i]==s[j]) {
                lps[i] = j+1;
            }
            else lps[i]=0;
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        int n = s.length();
        string temp = s;
        reverse(temp.begin(), temp.end());
        string temp2 = s+"#"+temp;
        vector<int>res = computeLPS(temp2);
        int ans = n-res[res.size()-1];
        temp = s.substr(s.length()-ans,ans);
        reverse(temp.begin(), temp.end());
        s = temp+s;
        return s;
    }
};