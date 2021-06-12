#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        //Computing the LPS array
        vector<int>lps(needle.size(),0);
        if(!haystack.size() && !needle.size()) return 0;
        int i=1, j=0;
        for(i=1;i<needle.size();i++) {
            j = lps[i-1];
            while(j>0 && needle[i]!=needle[j]) {
                j = lps[j-1];
            }
            if(needle[i]==needle[j]) {
                lps[i]=j+1;
            }
            else lps[i]=0;
        }
        i=0; j=0;
        while(i<haystack.size()) {
            while(j<needle.size() && i<haystack.size() && haystack[i]==needle[j]) {
                i++;
                j++;
            }
            if(j==needle.size()) return i-needle.size();
            if(j==0) i++;
            else j = lps[j-1];
        }
        return -1;
    }
};