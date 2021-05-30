#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //preprocessing step
        int n = nums.size();
        vector<int> product(n,0);
        product[n-1]=1;
        for (int i=n-2;i>=0;i--) {
            product[i]=product[i+1]*nums[i+1];
        }
        //left product;
        int prod = 1;
        vector<int> answer(n,0);
        for (int i=0; i<n;i++) {
            if (i!=0) prod*=nums[i-1];
            answer[i]=product[i]*prod;
        }
        return answer;
    }
};