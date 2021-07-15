class Solution
{
public:
    void backtrack(vector<string> &res, string curr_string, int open, int close, int max)
    {
        //Base case
        if (curr_string.length() == 2 * max)
        {
            res.push_back(curr_string);
        }
        //Recursive step
        if (open < max)
            backtrack(res, curr_string + "(", open + 1, close, max);
        if (close < open)
            backtrack(res, curr_string + ")", open, close + 1, max);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};