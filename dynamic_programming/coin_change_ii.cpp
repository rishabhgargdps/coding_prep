//Recursive solution
class Solution
{
public:
    int coin(vector<int> &coins, int amount, int start)
    {
        //Base cases
        if (amount < 0 || amount > 0 && start == coins.size())
            return -1;
        if (amount == 0 && start == coins.size())
            return 1;
        //Recursive step
        int left = coin(coins, amount, start + 1);
        int taken = coin(coins, amount - coins[start], start);
        if (left != -1 && taken != -1)
            return left + taken;
        else if (left != -1)
            return left;
        else if (taken != -1)
            return taken;
        else
            return -1;
    }

    int change(int amount, vector<int> &coins)
    {
        int ans = coin(coins, amount, 0);
        return ans == -1 ? 0 : ans;
    }
};

//Dp solution
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int m = coins.size();
        int n = amount;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int left = dp[i - 1][j];
                int taken = 0;
                if (j >= coins[i - 1])
                {
                    taken = dp[i][j - coins[i - 1]];
                }
                dp[i][j] = left + taken;
            }
        }
        return dp[m][n];
    }
};