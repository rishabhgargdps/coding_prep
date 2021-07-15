class Solution
{
public:
    int trailingZeroes(int n)
    {
        int temp = n;
        int i = 1;
        int res = 0;
        while (temp >= pow(5, i))
        {
            res += temp / pow(5, i);
            i++;
        }
        return res;
    }
};