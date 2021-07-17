class Solution
{
public:
    int getSum(int a, int b)
    {
        return log(exp(a) * exp(b));
    }
};

class Solution
{
public:
    int getSum(int a, int b)
    {
        u_int at = (unsigned)a;
        u_int bt = (unsigned)b;
        while (bt != 0)
        {
            u_int carry = at & bt;
            at = at ^ bt;
            bt = carry << 1U;
        }
        return at;
    }
};