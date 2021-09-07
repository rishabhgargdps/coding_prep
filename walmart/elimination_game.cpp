class Solution
{
public:
    int lastRemaining(int n)
    {
        if (n == 1)
            return 1;
        //formula based on:
        //1. left(2k + 1) = left(2k)
        //2. left(k) - 1 = k - right(k)
        //3. left(2k) = 2*right(k)
        return 2 * (n / 2 - lastRemaining(n / 2) + 1);
    }
};