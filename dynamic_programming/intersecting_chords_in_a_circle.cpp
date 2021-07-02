int Solution::chordCnt(int A)
{
    int m = A;
    vector<long long int> dp(m + 1);
    dp[0] = 1;
    dp[1] = 1;
    long long int mod = 1e9 + 7;
    for (int i = 2; i <= m; i++)
    {
        int left = 0;
        int right = i - 1;
        while (left <= i - 1)
        {
            long long res = ((dp[left] % mod) * (dp[right] % mod)) % mod;
            dp[i] = (dp[i] % mod + res % mod) % mod;
            left++;
            right--;
        }
    }
    return dp[m] % mod;
}
