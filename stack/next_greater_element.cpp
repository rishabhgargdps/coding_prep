#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int, int> m;
        vector<int>res;
        for (int i=0; i<nums2.size();i++) {
            while (!s.empty() && s.top() < nums2[i]) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }
        for (int i=0; i<nums1.size(); i++) {
            res.push_back(m[nums1[i]]);
        }
        return res;
    }
};