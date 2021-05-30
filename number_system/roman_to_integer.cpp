#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char, int>roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res=0, n= s.size();
        for (int i=0;i<n-1;i++) {
            if(roman.find(s[i])->second < roman.find(s[i+1])->second) res-=roman.find(s[i])->second;
            else res+=roman.find(s[i])->second;
        }
        res+=roman.find(s[n-1])->second;
        return res;
    }
};
int main() {
    Solution s;
    int res = s.romanToInt("LXXII");
    return res;
}