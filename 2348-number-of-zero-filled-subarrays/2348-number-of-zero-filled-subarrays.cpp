class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //n(n+1)/2
        unordered_map<long long, long long>m;
        long long cons_count = 0ll;
        if(nums.size() == 1 && nums[0] == 0) return 1ll;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == 0 && nums[i] == nums[i-1]) cons_count++;
            else if(nums[i-1] == 0 && nums[i] != 0) {
                m[++cons_count]++;
                // cout << cons_count << endl;
                cons_count = 0;
            }
            if(i == nums.size()-1 && nums[i] == 0) {
                // cout << cons_count << "i" << endl;
                m[++cons_count]++;
            }
        }
        long long res = 0ll;
        for(auto itr=m.begin(); itr!=m.end(); ++itr) {
            res += itr->second*(itr->first)*(itr->first+1)/2;
        }
        return res;
    }
};