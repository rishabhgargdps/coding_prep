class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, string> email_to_name;
        unordered_map<string, string> base;
        for (auto account : accounts)
        {
            string base_mail = account[1];
            string name = account[0];
            if (base.find(base_mail) != base.end())
                base_mail = base[account[1]];
            email_to_name[base_mail] = name;
            int i = 2;
            while (i < account.size())
            {
                if (base.find(account[i]) == base.end())
                {
                    base[account[i]] = base_mail;
                    i++;
                }
                else
                {
                    cout << "h";
                    base_mail = base[account[i]];
                    for (i = 2; i < account.size(); i++)
                    {
                        base[account[i]] = base_mail;
                    }
                    break;
                }
            }
            base[base_mail] = base_mail;
        }
        unordered_map<string, set<string>> ans;
        for (auto itr = base.begin(); itr != base.end(); ++itr)
        {
            ans[itr->second].insert(itr->first);
        }
        vector<vector<string>> res;
        for (auto itr = ans.begin(); itr != ans.end(); ++itr)
        {
            vector<string> temp;
            temp.push_back(email_to_name[itr->first]);
            email_to_name.erase(itr->first);
            for (auto it = ans[itr->first].begin(); it != ans[itr->first].end(); ++it)
            {
                temp.push_back(*it);
            }
            res.push_back(temp);
        }
        return res;
    }
};