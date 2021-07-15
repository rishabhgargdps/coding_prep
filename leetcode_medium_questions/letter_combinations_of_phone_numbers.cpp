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

class Solution
{
public:
    vector<string> char_map = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(vector<string> &res, string curr_string, const string &digits, int start)
    {
        //Base case
        if (start == digits.length())
        {
            res.push_back(curr_string);
            return;
        }
        //Recursive step
        int index = digits[start] - '0';
        for (char c : char_map[index])
        {
            backtrack(res, curr_string + c, digits, start + 1);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};
        vector<string> res;
        backtrack(res, "", digits, 0);
        return res;
    }
};