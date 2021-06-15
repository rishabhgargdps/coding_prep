//recursive solution (TLE )
class Solution {
public:
    int denomination(vector<int>&coins, int start, int amount) {
        //Base case
        if(amount<0) return -1;
        else if(amount==0) return 0;
        else if(start==coins.size()) return -1;
        int minimum = INT_MAX;
        int takeCoin = denomination(coins, start, amount-coins[start]);
        if(takeCoin!=-1) minimum = min(1+takeCoin,minimum);
        int withoutCoin = denomination(coins, start+1, amount);
        if(withoutCoin!=-1) minimum = min(withoutCoin,minimum);
        if(minimum == INT_MAX) {
            return -1;
        }
        //Recursive step
        return minimum;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        return denomination(coins, 0, amount);
    }
};

//dp solution (2D matrix tabulation)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int m = dp.size();
        int n = dp[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(j==0) dp[i][j]=0;
                else if (i==0) dp[i][j]=1e5;
                else if(coins[i-1]>j) {
                    dp[i][j] = dp[i-1][j]; //if coin value is greater than remaining amount, we have to exclude the coin
                }
                else {
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                }
            }
        }
        return dp[coins.size()][amount]==1e5?-1:dp[coins.size()][amount];
    }
};