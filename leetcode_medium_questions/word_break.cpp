class Solution
{
public:
    unordered_set<string> words;
    bool wb(string s, int pos)
    {
        if (pos == s.length())
            return true;
        for (int i = pos; i < s.length(); i++)
        {
            string temp = s.substr(pos, i - pos + 1);
            if (words.find(temp) != words.end() && wb(s, i + 1))
            {
                return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (string x : wordDict)
        {
            words.insert(x);
        }
        return wb(s, 0);
    }
};

//dp
class Solution
{
public:
    string getString(char x)
    {
        string s(1, x);
        return s;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words;
        for (string x : wordDict)
        {
            words.insert(x);
        }
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = words.find(getString(s[i - 1])) != words.end() ? 1 : 0;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int i = 1, j = i + len - 1; i <= n && j <= n; i++, j++)
            {
                string temp = s.substr(i - 1, j - i + 1);
                if (words.find(temp) != words.end())
                {
                    dp[i][j] = true;
                }
                else
                {
                    for (int k = i; k < j; k++)
                    {
                        dp[i][j] = dp[i][j] || (dp[i][k] && dp[k + 1][j]);
                    }
                }
            }
        }
        return dp[1][n];
    }
};