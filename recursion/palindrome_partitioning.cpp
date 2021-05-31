#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<string>>res;
class Solution {
public:
    bool isPalindrome(const string &s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void palindrome_partitioning(const string &s, int begin, int end, vector<string>currSet) {
        //Base case
        if(begin>end) {
            res.push_back(currSet);
            return;
        }
        //Recursive step
        for (int i=begin;i<=end;i++) {
            string str = s.substr(begin,i-begin+1);
            if (isPalindrome(str)) {
                currSet.push_back(str);
                palindrome_partitioning(s, i+1, end, currSet);
                currSet.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        res.clear();
        palindrome_partitioning(s, 0, n-1, {});
        return res;
    }
};