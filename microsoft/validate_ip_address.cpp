class Solution
{
public:
    vector<string> split(const string &IP, char delim)
    {
        vector<string> res;
        stringstream ss(IP);
        string item;
        while (getline(ss, item, delim))
        {
            res.push_back(item);
        }
        return res;
    }

    string validIPAddress(string IP)
    {
        if (IP == "")
            return "Neither";
        if (IP[IP.length() - 1] == '.')
            return "Neither";
        string ans = "IPv4";
        bool flag = true;
        vector<string> res = split(IP, '.');
        if (res.size() != 4)
        {
            ans = "IPv6";
            flag = false;
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i][0] == '0' && res[i] != "0")
            {
                ans = "IPv6";
                break;
            }
            for (char c : res[i])
            {
                if (c < '0' || c > '9')
                {
                    ans = "IPv6";
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
            if (res[i].length() > 3 || res[i] > "255")
            {
                ans = "IPv6";
                break;
            }
        }
        if (ans == "IPv4")
            return ans;
        if (IP[IP.length() - 1] == ':')
            return "Neither";
        res = split(IP, ':');
        if (res.size() != 8)
            return "Neither";
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i].length() < 1 || res[i].length() > 4)
            {
                return "Neither";
            }
            for (char c : res[i])
            {
                if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
                {
                    return "Neither";
                }
            }
        }
        return "IPv6";
    }
};