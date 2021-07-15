class Solution
{
public:
    int solve(int n)
    {
        int sum = 0;
        int digit = 0;
        while (n > 0)
        {
            digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        unordered_set<int> m;
        m.insert(n);
        while (true)
        {
            n = solve(n);
            if (m.find(n) == m.end())
                m.insert(n);
            else
                break;
        }
        if (n == 1)
            return true;
        return false;
    }
};