class Solution
{
public:
    class Compare
    {
    public:
        unordered_map<string, int> mp;
        Compare(unordered_map<string, int> &m)
        {
            mp = m;
        }
        bool operator()(string a, string b)
        {
            if (mp[a] != mp[b])
                return mp[a] < mp[b];
            return a > b;
        }
    };

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> res;
        unordered_map<string, int> m;
        for (string &word : words)
            m[word]++;
        priority_queue<string, vector<string>, Compare> pq((Compare(m)));
        for (auto itr = m.begin(); itr != m.end(); ++itr)
        {
            pq.push(itr->first);
        }
        while (k--)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};