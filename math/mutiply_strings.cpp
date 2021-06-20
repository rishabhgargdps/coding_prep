class Solution
{
public:
    string multiply(string num1, string num2)
    {
        vector<int> chs1(num1.size(), 0);
        for (int i = 0; i < num1.size(); i++)
        {
            chs1[i] = num1[i] - '0';
        }
        vector<int> chs2(num2.size(), 0);
        for (int i = 0; i < num2.size(); i++)
        {
            chs2[i] = num2[i] - '0';
        }
        vector<int> res(num1.size() + num2.size(), 0);

        for (int j = num2.size() - 1; j >= 0; j--)
        {
            for (int i = num1.size() - 1; i >= 0; i--)
            {
                int product = (chs1[i]) * (chs2[j]);
                int tmp = res[i + j + 1] + product;
                res[i + j + 1] = tmp % 10;
                res[i + j] += tmp / 10;
            }
        }

        string result = "";
        bool seen = false;
        for (int c : res)
        {
            if (c == 0 && !seen)
                continue;
            result += to_string(c);
            seen = true;
        }

        return result.length() == 0 ? "0" : result;
    }
};