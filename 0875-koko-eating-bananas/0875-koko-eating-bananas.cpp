class Solution {
public:
    bool valid(vector<int>& piles, int curr_k, int h) {
        long long res = 0;
        for(int x: piles) {
            if(x % curr_k == 0) res += x/curr_k;
            else res += x/curr_k + 1;
        }
        return res <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9+1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(valid(piles, mid, h)) right = mid-1;
            else left = mid+1;
        }
        return right+1;
    }
};