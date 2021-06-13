#include <iostream>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i=0; i<nums.size();i++) {
            while(i!=nums[i] && nums[i]<nums.size()) {
                swap(nums[i],nums[nums[i]]);
            }
        }
        int i=0;
        for(i=0; i<nums.size();i++) {
            if(i!=nums[i]) return i;
        }
        return i;
    }
};