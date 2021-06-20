class Solution
{
public:
    int myAtoi(string s)
    {
        long value = 0;
        int sign = 1;
        bool flag = true;
        int i = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        while (i < s.length())
        {
            if (isdigit(s[i]))
            {
                value = value * 10;
                value += (s[i] - '0');
                flag = false;
            }
            else if (s[i] == '+' && flag)
            {
                sign = 1;
                flag = false;
            }
            else if (s[i] == '-' && flag)
            {
                sign = -1;
                flag = false;
            }
            else
                break;
            if (value > pow(2, 31) - 1 && sign == 1)
                value = pow(2, 31) - 1;
            if (value > pow(2, 31) && sign == -1)
                value = pow(2, 31);
            i++;
        }
        value *= sign;
        return value;
    }
};