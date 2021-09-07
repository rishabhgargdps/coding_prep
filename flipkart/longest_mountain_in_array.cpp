class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        if (arr.size() < 3)
            return 0;
        int max_len = 0;
        int inc_len = 0;
        int dec_len = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[i - 1])
            {
                if (dec_len > 0)
                {
                    max_len = max(max_len, inc_len + dec_len + 1);
                    inc_len = 0;
                    dec_len = 0;
                }
                inc_len++;
            }
            else if (arr[i] < arr[i - 1])
            {
                if (inc_len > 0)
                {
                    dec_len++;
                }
                else
                    dec_len = 0;
            }
            else
            {
                if (dec_len > 0)
                {
                    max_len = max(max_len, inc_len + dec_len + 1);
                    dec_len = 0;
                }
                inc_len = 0;
            }
        }
        if (dec_len > 0)
            max_len = max(max_len, inc_len + dec_len + 1);
        return max_len;
    }
};