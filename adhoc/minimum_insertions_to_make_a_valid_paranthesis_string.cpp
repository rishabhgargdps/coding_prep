#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int count1=0,count2=0;
        int i=0;
        for (i=0;i<s.size();i++) {
            if (s[i]=='(') {
                count1+=2;
            }
            else if (s[i]==')' && s[i+1]==')' && count1>1) {
                count1-=2;
                i++;
            }
            else if (s[i]==')' && count1>0) {
                count1--;
            }
            else if (s[i]==')' && s[i+1]==')' && count1<=0) {
                count2++;
                i++;
            }
            else if (s[i]==')' && count1<=0) {
                count2+=2;
            }
        }
        return count1+count2;
    }
};