class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return 0;
        int res = 0;
        for(int i=0; i<(1<<n); i++) {
            int total = 0;
            for(int j=0; j<n; j++) {
                if(i & (1 << j)) {
                    total ^= nums[j];
                } 
            }
            res += total;
        }
        return res;
    }
};