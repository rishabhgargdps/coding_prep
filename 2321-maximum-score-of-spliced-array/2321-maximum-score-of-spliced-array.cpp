class Solution {
public:
    int max_sum(vector<int>& v) {
        int res = INT_MIN, curr_sum = 0;
        for(int i=0; i<v.size(); i++) {
            curr_sum += v[i];
            res = max(res, curr_sum);
            if(curr_sum < 0) curr_sum = 0;
        }
        return res;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int>diff1(nums1.size());
        vector<int>diff2(nums1.size());
        for(int i=0; i<nums1.size(); i++) {
            diff1[i] = nums1[i]-nums2[i];
            diff2[i] = nums2[i]-nums1[i];
        }
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int res1 = sum1+max_sum(diff2);
        int res2 = sum2+max_sum(diff1);
        return max(res1, res2);
    }
};