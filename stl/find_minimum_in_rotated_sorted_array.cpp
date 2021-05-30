#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binary_search(vector<int>&nums, int start, int end) {
        if (nums[start]<=nums[end]) return nums[start];
        int mid = start + (end-start)/2;
        if (nums[mid]>=nums[start]) return binary_search(nums, mid+1, end);
        return binary_search(nums, start, mid);
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // return *min_element(nums.begin(), nums.end());
        return binary_search(nums, 0, n-1);
    }
};
int main() {
    Solution s;
    vector<int>v={};
    int n = v.size();
    return s.binary_search(v,0,n-1);
}