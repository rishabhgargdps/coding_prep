#include<iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0, current=0;
        stack<int>stk;
        while(current < height.size()) {
            while(!stk.empty() && height[current] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int distance = current - stk.top() - 1;
                int bounded_height = min(height[stk.top()], height[current]) - height[top];
                ans+=distance*bounded_height;
            }
            stk.push(current++);
        }
        return ans;
    }
};