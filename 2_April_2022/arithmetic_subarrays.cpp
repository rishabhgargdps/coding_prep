class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>res(l.size(), true);
        // unordered_set<int>s;
        // for(int i=0; i<l.size(); i++) {
        //     s.clear();
        //     int maximum = INT_MIN, minimum = INT_MAX;
        //     for(int j=l[i]; j<=r[i]; j++) {
        //         if(s.find(nums[j]) != s.end()) {
        //             res[i] = false;
        //             break;
        //         }
        //         s.insert(nums[j]);
        //         maximum = max(maximum, nums[j]);
        //         minimum = min(minimum, nums[j]);
        //     }
        //     int d = maximum - minimum;
        //     if(d%(r[i]-l[i])) {
        //         res[i] = false;
        //         continue;
        //     }
        //     d /= (r[i]-l[i]);
        //     int temp;
        //     for(temp = maximum; temp >= minimum; temp = temp-d) {
        //         if(s.find(temp) == s.end()) {
        //             res[i] = false;
        //             break;
        //         }
        //     }
        // }
        vector<int>temp(nums.begin(), nums.end());
        for(int i=0; i<l.size(); i++) {
            sort(temp.begin()+l[i], temp.begin()+r[i]+1);
            int diff = temp[l[i]+1]-temp[l[i]];
            for(int j=l[i]+1; j<r[i];j++) {
                if(diff != temp[j+1]-temp[j]) res[i] = false;
            }
            temp = nums;
        }
        return res;
    }
};