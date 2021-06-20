class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string res = "";
        if (numerator == 0)
            return "0";
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
        {
            res += "-";
        }
        long dividend = abs(numerator);
        long divisor = abs(denominator);
        long remainder = dividend % divisor;
        res += to_string(dividend / divisor);
        if (remainder == 0)
            return res;
        res += ".";
        map<long, long> m;
        while (remainder != 0)
        {
            if (m[remainder] > 0)
            {
                res.insert(m[remainder], "(");
                res += ")";
                break;
            }
            m[remainder] = res.length(); //length is taken to get the position of ( in case we encounter the same remainder in the next iteration
            remainder *= 10;
            res += to_string(remainder / divisor);
            remainder %= divisor;
        }
        return res;
    }
};