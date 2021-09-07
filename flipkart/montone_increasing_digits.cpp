class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num = to_string(n);
        int len = num.length();
        int i = 0;
        int cliff = len - 1;
        while (i < cliff)
        {
            if (num[i] > num[i + 1])
            {
                cliff = i;
                num[i] = ((num[i] - '0') - 1) + '0';
                i = 0;
            }
            else
                i++;
        }
        for (i = cliff + 1; i < len; i++)
        {
            num[i] = '9';
        }
        return stoi(num);
    }
};