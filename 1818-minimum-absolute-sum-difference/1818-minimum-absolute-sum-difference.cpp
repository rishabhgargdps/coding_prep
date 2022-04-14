class Solution {
public:
    const int64_t MOD = 1e9 + 7;
        
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        
        vector<int> diff(n);
        int64_t diffSum = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            diffSum += diff[i];
        }
        
        sort(nums1.begin(), nums1.end());
        
        int64_t bestSave = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x = nums2[i];
            int idx = lower_bound(nums1.begin(), nums1.end(), x) - nums1.begin();
            int d = INT_MAX;
            if (idx == 0) d = min(d, nums1[idx] - x);
            else if (idx == n) d = min(d, x - nums1[n-1]);
            else {
                d = min(d, nums1[idx] - x);
                d = min(d, x - nums1[idx-1]);
            }
            //printf("x = %d, idx = %d, d = %d\n", x, idx, d);
            bestSave = max(bestSave, (int64_t)abs(diff[i] - d));
        }
        
        return (diffSum - bestSave) % MOD;
    }
};
