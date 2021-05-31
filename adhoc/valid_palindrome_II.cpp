#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isPalindrome(string s, int l, int h) {
        int i=l,j=h;
        while(i<=j) {
            if(s[i]!=s[j]) return i;
            i++;
            j--;
        }
        return -1;
    }
    bool validPalindrome(string s) {
        int partition = isPalindrome(s,0,s.size()-1);
        if(partition!=-1) {
            int partition_2 = min(isPalindrome(s,partition+1,s.size()-1-partition),isPalindrome(s,partition,s.size()-partition-2));
            if(partition_2!=-1) return false;
        }
        return true;
    }
};