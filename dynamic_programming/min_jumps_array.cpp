//can be solved through dp but I have used greedy approach
bool can_reach(vector<int> &A)
{
    int n = A.size();
    int j = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (j <= i + A[i])
        {
            j = i;
        }
    }
    return j == 0;
}

int Solution::jump(vector<int> &A)
{
    if (A.size() == 1)
        return 0;
    if (!can_reach(A))
        return -1;
    int maximum = A[0];
    int current_end = A[0];
    int count = 1;
    for (int i = 0; i < A.size(); i++)
    {
        if (i == A.size() - 1)
            return count;
        maximum = max(maximum, i + A[i]);
        if (i == current_end)
        {
            count++;
            current_end = maximum;
        }
    }
    return count;
}
