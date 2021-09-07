class Solution
{
public:
    vector<string> res;

    void backtrack(string s, string curr, int curr_length, int index, int count)
    {
        string temp = s.substr(index - curr_length, curr_length);
        //Pruning
        if ((curr_length == 3 && temp > "256") || (temp[0] == '0' && temp != "0"))
            return;

        //Positive case
        if (index == s.length() && (curr_length < 3 || (curr_length == 3 && temp < "256")) && count == 4)
        {
            res.push_back(curr);
            return;
        }
        //Negative case
        if (index >= s.length() || count > 4)
            return;

        //Recursive step
        backtrack(s, curr + "." + s.substr(index, 1), 1, index + 1, count + 1);
        backtrack(s, curr + "." + s.substr(index, 2), 2, index + 2, count + 1);
        backtrack(s, curr + "." + s.substr(index, 3), 3, index + 3, count + 1);
    }

    vector<string> restoreIpAddresses(string s)
    {
        backtrack(s, "", 0, 0, 0);
        for (string &s : res)
        {
            s.erase(0, 1);
        }
        return res;
    }
};