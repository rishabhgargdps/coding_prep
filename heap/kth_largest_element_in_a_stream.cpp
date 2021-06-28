#include <iostream>
using namespace std;
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minq;
    int x;
    KthLargest(int k, vector<int>& nums) {
        x=k;
        for(int i=0; i<nums.size();i++) {
            minq.push(nums[i]);
        }
    }
    
    int add(int val) {
        while(minq.size() > x) {
            minq.pop();
        }
        if (minq.size() == x) {
            minq.push(val);
            minq.pop();
        }
        else if (minq.size() < x) {
            minq.push(val);
        }
        return minq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */