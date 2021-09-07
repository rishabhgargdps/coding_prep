//TLE
class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n)
    {
        if (n == 0)
            return cells;
        vector<int> res(cells.size());
        res[0] = res.back() = 0;
        while (n--)
        {
            for (int i = 1; i < cells.size() - 1; i++)
            {
                res[i] = cells[i - 1] ^ cells[i + 1];
            }
            for (int i = 0; i < cells.size(); i++)
            {
                cells[i] = res[i];
            }
        }
        return res;
    }
};

//map / lookup table
class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n)
    {
        vector<vector<int>> lookup;
        vector<int> res(cells.size());
        while (n--)
        {
            for (int i = 1; i < res.size() - 1; i++)
            {
                res[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            }
            if (lookup.size() > 0 && lookup.front() == res)
                return lookup[n % lookup.size()];
            lookup.push_back(res);
            cells = res;
        }
        return res;
    }
};