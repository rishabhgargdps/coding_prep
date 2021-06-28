#include <iostream>
using namespace std;
// class Solution {
// public:
    // int findKthLargest(vector<int>& nums, int k) {
    //     //we implement this using a max heap
    //     priority_queue<int> maxq(nums.begin(),nums.end());
    //     while(--k) {
    //         maxq.pop();
    //     }
    //     return maxq.top();
    // }
// };
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //we implement this using a min heap
        priority_queue<int, vector<int>, greater<int>> minq(nums.begin(), nums.begin()+k);
        for (int i=k; i<nums.size();i++) {
            minq.push(nums[i]);
            minq.pop();
        }
        return minq.top();
    }
};