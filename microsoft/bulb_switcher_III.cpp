class Solution
{
public:
    int numTimesAllBlue(vector<int> &light)
    {
        int curr_sum = 0, sum_till_k = 0, count = 0;
        for (int k = 0; k < light.size(); k++)
        {
            curr_sum += light[k];
            sum_till_k += (k + 1);
            if (curr_sum == sum_till_k)
                count++;
        }
        return count;
    }
};