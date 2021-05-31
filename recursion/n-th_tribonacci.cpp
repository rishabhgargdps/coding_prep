#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        //Recursive implementation
        // if (n==0) return 0;
        // if (n==1 || n==2) return 1;
        // return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        
        //Tabulation dp
        vector<int>res(n+1,0);
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        res[0]=0;
        res[1]=1;
        res[2]=1;
        for(int i=3;i<n+1;i++) {
            res[i]=res[i-3]+res[i-2]+res[i-1];
        }
        return res[n];
    }
};