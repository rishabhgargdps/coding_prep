#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s)
    {
        // int count1=0, count2=0, count3=0, count4=0;
        // int i=0;
        // while(i<s.size()) {
        //     if(s[i]=='(' && s[i+1]=='(') {
        //         count1+=2;
        //         i++;
        //     }
        //     else if(s[i]=='(' && s[i+1]==')' && s[i+2]==')') {
        //         i+=3;
        //     }
        //     else if(s[i]=='(' && s[i+1]==')' && s[i+2]=='(') {
        //         count3++;
        //         i+=2;
        //     }
        //     else if(s[i]==')' && s[i+1]==')' && count1>0) {
        //         count1-=2;
        //         i+=2;
        //     }
        //     else if(s[i]==')' && s[i+1]==')' && count1==0) {
        //         count2++;
        //         i+=2;
        //     }
        //     else if(s[i]==')' && s[i+1]=='(' && count1>0) {
        //         count1--;
        //         i++;
        //     }
        //     else if(s[i]==')' && s[i+1]=='(' && count1==0) {
        //         count4+=2;
        //         i++;
        //     }
        //     else if(i==s.size()-2) {
        //         if(s[s.size()-2]=='(' && s[s.size()-1]==')') count3++;
        //         break;
        //     }
        //     else if(i==s.size()-1) {
        //         if(s[s.size()-1]=='(') count1+=2;
        //         else if(count1) count1--;
        //         else if(!count1) count4+=2;
        //         break;
        //     }
        // }
        // cout << count1 << " " << count2 << " " << count3 << " " << count4 << endl;
        // return count1+count2+count3+count4;
        int opens = 0;

        int i = 0;

        int result = 0;

        while (i < s.size()) {
            if (s[i] == '(') {
                ++opens;
                ++i;
            } else {
                if (i + 1 < s.size() && s[i + 1] == ')') { // consecutive '))'
                    if (opens == 0) { // no opens
                        ++result; // add an opening
                    } else { // has openings
                        --opens; // pop off an opening
                    }
                    i += 2;
                } else { // single ')'
                    if (opens > 0) {
                        ++result; // add an extra ')'
                        --opens;
                    } else {
                        result += 2; // add an ')' and '('
                    }
                    ++i;
                }
            }
        }

        result += (opens * 2);

        return result;
    }
};