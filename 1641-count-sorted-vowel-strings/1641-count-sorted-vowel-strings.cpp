class Solution {
public:
    int countVowelStrings(int n) {
        int  m = 6;
        vector<vector<int>>dp(n+1, vector<int>(m));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++){
                dp[i][j]=dp[i][j-1]+(i>1?dp[i-1][j]:1);
            }
        }
        return (n+4)*(n+3)*(n+2)*(n+1)/24;
        return dp[n][5];
    }
};