class Solution
{
public:
    string reorganizeString(string s)
    {

        //         create a frequency map of all characters
        unordered_map<char, int> mp;

        for (auto x : s)
            mp[x]++;

        priority_queue<pair<int, char>> pq;

        //         push freq with characters to maxheap
        for (auto x : mp)
            pq.push({x.second, x.first});

        string res = "";

        while (pq.size() > 1)
        {
            //             take top two elements add them to res and decrese their count
            auto x = pq.top();
            pq.pop();

            auto y = pq.top();
            pq.pop();

            res += x.second;
            res += y.second;

            x.first--;
            y.first--;

            if (x.first > 0)
            {
                pq.push(x);
            }

            if (y.first > 0)
            {
                pq.push(y);
            }
        }

        if (!pq.empty())
        {

            auto z = pq.top();
            if (z.first > 1)
            {
                //                 so its not possible
                return "";
            }
            else
            {
                res += z.second;
            }
        }
        return res;
    }
};