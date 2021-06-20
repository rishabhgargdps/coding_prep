//tle error
class Solution
{
public:
    int countPairs(vector<int> &deliciousness)
    {
        int res = 0;
        long mod = 1e9 + 7;
        unordered_map<long, long> m;
        for (auto x : deliciousness)
            m[x]++;
        for (auto x : deliciousness)
        {
            for (int i = 0; i <= 21; i++)
            {
                int z = 1 << i;
                int y = z - x;
                if (y == x)
                    res += m[y] - 1;
                else
                    res += m[y];
                res %= mod;
            }
        }
        return (res / 2) % mod;
    }
};

//correct solution
class Solution
{
public:
    int countPairs(vector<int> &deliciousness)
    {
        int res = 0;
        long mod = 1e9 + 7;
        unordered_map<long, long> m;
        sort(deliciousness.begin(), deliciousness.end());
        for (auto x : deliciousness)
        {
            for (int i = 0; i <= 21; i++)
            {
                int z = 1 << i;
                int y = z - x;
                if (y > x)
                    break; //not a necessary condition, just for optimizing
                res += m[y];
                res %= mod;
            }
            m[x]++;
        }
        return res;
    }
};