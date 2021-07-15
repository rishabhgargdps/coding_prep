class Solution
{
public:
    string countAndSay(int n)
    {
        //Base case
        if (n == 1)
            return "1";
        //Recursive step
        string s = countAndSay(n - 1);
        //Processing
        string res = "";
        int count = 1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
                count++;
            else
            {
                res += to_string(count) + s[i];
                count = 1;
            }
        }
        res += to_string(count) + s[s.length() - 1];
        return res;
    }
};