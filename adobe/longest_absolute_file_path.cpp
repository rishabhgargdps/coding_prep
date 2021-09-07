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

    int lengthLongestPath(string input)
    {
        int start_index = 0;
        int max_len = 0, curr_len = 0;
        vector<string> input_split = split(input, '\n');
        stack<int> stk;

        for (int i = 0; i < input_split.size(); i++)
        {
            string temp = input_split[i];
            int level = count(temp.begin(), temp.end(), '\t');
            while (level < stk.size())
            {
                curr_len -= stk.top();
                stk.pop();
            }

            curr_len += (temp.length() - level);
            stk.push(temp.length() - level);
            if (temp.find('.') != string::npos)
                max_len = max(max_len, curr_len + level);
        }

        return max_len;
    }
};