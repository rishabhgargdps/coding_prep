class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> s1;
        vector<int> s2;
        stringstream temp1(version1);
        string intermediate;
        while (getline(temp1, intermediate, '.'))
        {
            s1.push_back(stoi(intermediate));
        }
        stringstream temp2(version2);
        while (getline(temp2, intermediate, '.'))
        {
            s2.push_back(stoi(intermediate));
        }
        int i = 0;
        int j = 0;
        while (i < s1.size() && j < s2.size())
        {
            if (s1[i] > s2[j])
                return 1;
            else if (s1[i] < s2[j])
                return -1;
            i++;
            j++;
        }
        while (i < s1.size())
        {
            if (s1[i] > 0)
                return 1;
            i++;
        }
        while (j < s2.size())
        {
            if (s2[j] > 0)
                return -1;
            j++;
        }
        return 0;
    }
};