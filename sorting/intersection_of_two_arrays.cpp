#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> arr1(nums1.begin(),nums1.end()), arr2(nums2.begin(), nums2.end());
        vector<int>res;
        auto i = arr1.begin(), j = arr2.begin();
        while(i!=arr1.end() && j!=arr2.end()) {
            if (*i == *j) {
                res.push_back(*i);
                i++;
                j++;
            }
            else if (*i<*j) {
                i++;
            }
            else j++;
        }
        return res;
    }
};