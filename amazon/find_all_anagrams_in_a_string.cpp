class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        unordered_map<char, int> m;
        for (char c : p)
        {
            m[c]++;
        }
        int start = 0;
        for (int end = 0; end < s.length(); end++)
        {
            m[s[end]]--;
            if (m[s[end]] == 0)
                m.erase(s[end]);
            if (end - start + 1 > p.length())
            {
                m[s[start]]++;
                if (m[s[start]] == 0)
                    m.erase(s[start]);
                start++;
            }
            if (m.empty())
                res.push_back(start);
        }
        return res;
    }
};