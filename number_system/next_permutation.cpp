#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void swap (int &x, int &y) {
        int temp =x;
        x=y;
        y=temp;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i=n-2;
        for (; i>=0; i--) {
            if (nums[i]<nums[i+1]) break;
        }
        int j;
        if (i<0) sort(nums.begin(), nums.end());
        else {
            sort(nums.begin()+i+1,nums.end());
            //find the number which is just greater;
            // swap(nums[i], nums[std::upper_bound(nums.begin(), nums.end(), nums[i])-nums.begin()]);
            for (j=i+1;j<n;j++) {
                if (nums[j]>nums[i]) break;
            }
            swap(nums[i],nums[j]);
        };
        for (j=0; j<n; j++){
            cout << nums[j];
        }
    }
};