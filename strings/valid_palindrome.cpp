#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i=0; i<s.size(); i++) {
            if ((s[i]<'A' || s[i]>'Z') && (s[i]<'a' || s[i]>'z') && (s[i]<'0' || s[i]>'9')) {
                s.erase(i,1);
                i--;
            }
        }
        string temp=s;
        reverse(s.begin(),s.end());
        return s==temp;
    }
};