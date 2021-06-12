#include <iostream>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (long int i=0l; i<nums.size(); i++) {
            while (i!=nums[i]-1l && nums[i]>0 && nums[i] <= nums.size() && nums[i]!=nums[nums[i]-1l]) {
                swap(nums[i],nums[nums[i]-1l]);
            }
        }
        long int i=0l;
        for (i=0l; i<nums.size(); i++) {
            if(i!=nums[i]-1l) return i+1l;
        }
        return i+1l;
    }
};