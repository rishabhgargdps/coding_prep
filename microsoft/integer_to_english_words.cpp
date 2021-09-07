class Solution
{
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        vector<vector<string>> numeral = {{"", ""}, {"One ", "Ten "}, {"Two ", "Twenty "}, {"Three ", "Thirty "}, {"Four ", "Forty "}, {"Five ", "Fifty "}, {"Six ", "Sixty "}, {"Seven ", "Seventy "}, {"Eight ", "Eighty "}, {"Nine ", "Ninety "}};
        vector<string> append = {"", "Thousand ", "Million ", "Billion "};
        unordered_map<string, string> m = {{"Ten One", "Eleven"}, {"Ten Two", "Twelve"}, {"Ten Three", "Thirteen"}, {"Ten Four", "Fourteen"}, {"Ten Five", "Fifteen"}, {"Ten Six", "Sixteen"}, {"Ten Seven", "Seventeen"}, {"Ten Eight", "Eighteen"}, {"Ten Nine", "Nineteen"}};
        string number = to_string(num);
        reverse(number.begin(), number.end());
        int count = 0;
        string res = "";
        for (int i = 0; i < number.length(); i++)
        {
            if (i % 3 == 0)
            {
                res = numeral[number[i] - '0'][0] + number[i] == '0' ? "" : append[count] + res;
            }
            else if (i % 3 == 1)
            {
                res = numeral[number[i] - '0'][1] + res;
            }
            else if (i % 3 == 2)
            {
                res = numeral[number[i] - '0'][0] + (number[i] == '0' ? "" : "Hundred ") + res;
                count++;
            }
        }
        vector<string> repl;
        istringstream s(res);
        string temp;
        while (s >> temp)
        {
            repl.push_back(temp);
        }
        for (int i = 0; i < repl.size() - 1; i++)
        {
            temp = repl[i] + " " + repl[i + 1];
            if (m.find(temp) != m.end())
            {
                repl[i] = m[temp];
                repl[i + 1] = "";
            }
        }
        res = "";
        for (int i = 0; i < repl.size(); i++)
        {
            res += repl[i] + (i + 1 < repl.size() && repl[i + 1] == "" ? "" : " ");
        }
        return res.substr(0, res.length() - 1);
    }
};