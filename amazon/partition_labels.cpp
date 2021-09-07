class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> res;
        int start = 0;
        int end = 0;
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]].push_back(i);
        }
        while (end <= s.length() - 1)
        {
            end = max(end, m[s[start]].back());
            for (int i = start + 1; i <= end; i++)
            {
                end = max(end, m[s[i]].back());
            }
            res.push_back(end - start + 1);
            start = end + 1;
            end++;
        }
        return res;
    }
};