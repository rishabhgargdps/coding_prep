class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> ans;
        istringstream ss(s);
        string temp;
        while (ss >> temp)
        {
            ans.push_back(temp);
        }
        string res = "";
        reverse(ans.begin(), ans.end());
        for (string temp : ans)
        {
            res += temp + " ";
        }
        res = res.substr(0, res.length() - 1);
        return res;
    }
};