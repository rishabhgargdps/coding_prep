//wrong solution
class Solution
{
public:
    vector<vector<int>> res;

    void combinations(vector<int> &candidates, int target, int curr_index, vector<int> curr)
    {
        //Positive case
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }
        //Negative case
        if (target < 0)
            return;
        if (curr_index == candidates.size())
            return;

        //Recursive step
        //include
        curr.push_back(candidates[curr_index]);
        combinations(candidates, target - candidates[curr_index], curr_index + 1, curr);

        //exclude
        curr.pop_back();
        combinations(candidates, target, curr_index + 1, curr);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        res.clear();
        sort(candidates.begin(), candidates.end());
        combinations(candidates, target, 0, {});
        sort(res.begin(), res.end());
        for (int i = 0; i < (int)res.size() - 1; i++)
        {
            if (res[i] == res[i + 1])
            {
                res.erase(res.begin() + i);
                i--;
            }
        }
        return res;
    }
};

//correct solution
class Solution
{
public:
    vector<vector<int>> res;

    void combinations(vector<int> &candidates, int target, int curr_index, vector<int> curr)
    {
        //Positive case
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }
        //Negative case
        if (target < 0)
            return;

        //Recursive step
        for (int i = curr_index; i < candidates.size(); i++)
        {
            if (i == curr_index || candidates[i] != candidates[i - 1])
            {
                //include
                curr.push_back(candidates[i]);
                combinations(candidates, target - candidates[i], i + 1, curr);
                //exclude
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        res.clear();
        sort(candidates.begin(), candidates.end());
        combinations(candidates, target, 0, {});
        return res;
    }
};