#include <iostream>
using namespace std;

vector<vector<int>> create_subsets(vector<char> &arr)
{
    int n = arr.size();
    vector<vector<char>> res;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<char> currSet = {};
        for (int j = 0; j < n; j++)
        {
            if (mask && (1 << j))
            {
                currSet.push_back(arr[j]);
            }
        }
        res.push_back(currSet);
    }
    return res;
}

int main()
{
    return 0;
}