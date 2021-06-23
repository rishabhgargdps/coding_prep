class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0;
        int r = x;
        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (mid == x / mid)
                return mid;
            else if (mid < x / mid)
                l = mid;
            else
                r = mid;
        }
        if (r != 0 && r == x / r)
            return r;
        return l;
    }
};