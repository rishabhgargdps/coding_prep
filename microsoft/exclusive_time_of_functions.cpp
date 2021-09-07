class Solution
{
public:
    vector<string> split(string &s, char delim)
    {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
        {
            res.push_back(item);
        }
        return res;
    }

    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        stack<pair<int, int>> stk;
        vector<int> res(logs.size(), 0);
        for (string log : logs)
        {
            vector<string> temp = split(log, ':');
            int curr_num = stoi(temp[0]);
            string status = temp[1];
            int time = stoi(temp[2]);
            if (status == "start")
            {
                if (!stk.empty())
                    res[stk.top().first] += time - stk.top().second;
                stk.push({curr_num, time});
            }
            else if (status == "end")
            {
                res[stk.top().first] += time + 1 - stk.top().second;
                stk.pop();
                if (!stk.empty())
                    stk.top().second = time + 1;
            }
        }
        while (res[res.size() - 1] == 0)
        {
            res.pop_back();
        }
        return res;
    }
};