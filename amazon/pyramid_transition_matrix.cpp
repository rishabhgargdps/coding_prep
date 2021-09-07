class Solution
{
public:
    bool bfs(vector<vector<char>> &buffer, unordered_map<string, vector<char>> &m, int i, int j)
    {
        //Base case
        if (i < 0)
            return true;
        if (j > i)
            return bfs(buffer, m, i - 1, 0);
        //Recursive step
        string curr = "";
        curr = curr + buffer[i + 1][j] + buffer[i + 1][j + 1];
        for (char c : m[curr])
        {
            buffer[i][j] = c;
            if (bfs(buffer, m, i, j + 1))
                return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        int n = bottom.length();
        vector<vector<char>> buffer(n, vector<char>(n));
        for (int i = 0; i < bottom.length(); i++)
        {
            buffer[n - 1][i] = bottom[i];
        }
        unordered_map<string, vector<char>> m;
        for (string s : allowed)
        {
            m[s.substr(0, 2)].push_back(s[2]);
        }
        return bfs(buffer, m, n - 2, 0);
    }
};