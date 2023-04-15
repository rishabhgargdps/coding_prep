class Solution {
public:
    int solve(vector<vector<int>>& piles, int pointer_index, int k, vector<vector<int>>& dp) {
        if(pointer_index == piles.size()) return 0;
        if(dp[pointer_index][k] != -1) return dp[pointer_index][k];
        int maximum = solve(piles, pointer_index+1, k, dp);
        for(int j=0; j<piles[pointer_index].size(); j++) {
            if(j+1 <= k) maximum = max(maximum, piles[pointer_index][j] + solve(piles, pointer_index+1, k-j-1, dp));
            else break;
        }
        return dp[pointer_index][k] = maximum;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i=0; i<piles.size(); i++) {
            for(int j=1; j<piles[i].size(); j++) {
                piles[i][j] += piles[i][j-1];
            }
        }
        vector<vector<int>>dp(piles.size(), vector<int>(k+1, -1));
        return solve(piles, 0, k, dp);
    }
};