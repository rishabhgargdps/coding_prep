class Solution
{
public:
    vector<string> split(const string &s, char delim)
    {
        vector<string> result;
        stringstream ss(s);
        string item;

        while (getline(ss, item, delim))
        {
            result.push_back(item);
        }
        return result;
    }

    string solveEquation(string equation)
    {
        for (int i = 0; i < equation.size(); i++)
        {
            if (equation[i] == '-')
            {
                equation.insert(i, "+");
                i++;
            }
        }
        int index = equation.find('=');
        string left = equation.substr(0, index);
        string right = equation.substr(index + 1);
        vector<string> left_temp = split(left, '+');
        vector<string> right_temp = split(right, '+');
        for (string &s : left_temp)
        {
            if (s.back() != 'x')
            {
                if (s[0] == '-')
                {
                    right_temp.push_back(s.substr(1));
                }
                else
                {
                    right_temp.push_back("-" + s);
                }
                s = "0x";
            }
        }
        for (string &s : right_temp)
        {
            if (s.back() == 'x')
            {
                if (s[0] == '-')
                {
                    left_temp.push_back(s.substr(1));
                }
                else
                {
                    left_temp.push_back("-" + s);
                }
                s = "0";
            }
        }
        for (string &s : left_temp)
        {
            if (s == "x")
                s = "1";
            else if (s == "-x")
                s = "-1";
            else
                s = s.substr(0, s.length() - 1);
        }
        int sum_left = 0;
        int sum_right = 0;
        for (string s : left_temp)
        {
            sum_left += s.empty() ? 0 : stoi(s);
        }
        for (string s : right_temp)
        {
            sum_right += s.empty() ? 0 : stoi(s);
        }
        if (sum_left == 0 && sum_right == 0)
            return "Infinite solutions";
        if (sum_left == 0)
            return "No solution";
        int ans = sum_right / sum_left;
        string res = "x=" + to_string(ans);
        return res;
    }
};