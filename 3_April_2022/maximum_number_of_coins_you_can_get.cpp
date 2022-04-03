class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res = 0;
        int n = piles.size();
        sort(piles.begin(), piles.end());
        for(int i=0; i<n/3; i++) {
            res += piles[n-1-2*i-1];
        }
        return res;
    }
};