class Solution
{
public:
    unordered_map<string, bool> m;
    string s1, s2, s3;
    int len1, len2, len3;
    bool check(int p1, int p2, int p3)
    {
        //Base case
        if (p1 == len1 && p2 == len2 && p3 == len3)
            return true;
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        if (m.find(key) != m.end())
            return m[key];

        //Recursive step
        if (p1 == len1)
        {
            m[key] = s2[p2] == s3[p3] ? check(p1, p2 + 1, p3 + 1) : false;
        }
        if (p2 == len2)
        {
            m[key] = s1[p1] == s3[p3] ? check(p1 + 1, p2, p3 + 1) : false;
        }
        bool one = false, two = false;
        if (s1[p1] == s3[p3])
        {
            one = check(p1 + 1, p2, p3 + 1);
        }
        if (s2[p2] == s3[p3])
        {
            two = check(p1, p2 + 1, p3 + 1);
        }
        m[key] = one || two;
        return m[key];
    }

    bool isInterleave(string x, string y, string z)
    {
        s1 = x;
        s2 = y;
        s3 = z;
        len1 = s1.length();
        len2 = s2.length();
        len3 = s3.length();
        if (len1 + len2 != len3)
            return false;
        return check(0, 0, 0);
    }
};