class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int curr_sum = 0;
        for(int i=0; i<gain.size(); i++) {
            curr_sum += gain[i];
            res = max(res, curr_sum);
        }
        return res;
    }
};