class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> m;
        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                if (m[s[i]] != t[i])
                    return false;
            }
            else
                m[s[i]] = t[i];
        }
        unordered_set<char> dup;
        for (auto itr = m.begin(); itr != m.end(); ++itr)
        {
            if (dup.find(itr->second) != dup.end())
                return false;
            dup.insert(itr->second);
        }
        return true;
    }
};