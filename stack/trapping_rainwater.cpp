#include<iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left;
        int max_height = INT_MIN;
        for (int l : height) {
            max_height = max(max_height, l);
            left.push_back(max_height);
        }
        int right[height.size()];
        max_height = INT_MIN;
        for (int i=height.size()-1; i>=0; i--) {
            max_height = max(max_height, height[i]);
            right[i] = max_height;
        }
        int sum=0;
        for (int i=0; i<height.size();i++) {
            sum+=min(left[i],right[i])-height[i];
        }
        return sum;
    }
};