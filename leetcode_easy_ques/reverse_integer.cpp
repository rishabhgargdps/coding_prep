class Solution
{
public:
    int reverse(int x)
    {
        long temp = abs(x);
        long res = 0;
        while (x > 0)
        {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        if (res > INT_MAX)
            return 0;
        return x >= 0 ? res : -res;
    }
};