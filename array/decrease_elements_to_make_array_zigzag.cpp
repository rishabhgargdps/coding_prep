#include <iostream>
using namespace std;
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        //we can compare both the approaches (brute force method)
        int count1 = 0, count2 = 0;
        nums.push_back(1001);
        nums.insert(nums.begin(),1001);
        for (int i=1; i<nums.size()-1; i+=2) {
            count1+=max(nums[i]-min(nums[i+1],nums[i-1])+1,0);
        }
        for (int i=2; i<nums.size()-1; i+=2) {
            count2+=max(nums[i]-min(nums[i+1],nums[i-1])+1,0);
        }
        return min(count1, count2);
    }
};