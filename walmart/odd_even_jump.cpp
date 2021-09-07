class Solution
{
public:
    int oddEvenJumps(vector<int> &arr)
    {
        int res = 1;
        int n = arr.size();
        vector<bool> higher(n), lower(n);
        higher[n - 1] = true;
        lower[n - 1] = true;
        map<int, int> m;
        m[arr[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            auto hi = m.lower_bound(arr[i]), lo = m.upper_bound(arr[i]);
            if (hi != m.end())
                higher[i] = lower[hi->second];
            if (lo != m.begin())
                lower[i] = higher[(--lo)->second];
            if (higher[i])
                res++;
            m[arr[i]] = i;
        }
        return res;
    }
};