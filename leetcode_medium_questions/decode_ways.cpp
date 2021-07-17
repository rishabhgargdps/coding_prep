class Solution
{
public:
    int numDecodings(string s)
    {
        //remove the leading zeros
        // while(s.length() > 1 && s[0] == '0') s.erase(0, 1);
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= s.length(); i++)
        {
            int lengthOne = stoi(s.substr(i - 1, 1));
            int lengthTwo = stoi(s.substr(i - 2, 2));
            if (lengthOne >= 1 && lengthOne <= 9)
            {
                dp[i] += dp[i - 1];
            }
            if (lengthTwo >= 10 && lengthTwo <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};