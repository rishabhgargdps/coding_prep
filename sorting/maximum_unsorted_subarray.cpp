vector<int> Solution::subUnsort(vector<int> &A)
{
    vector<int> res;
    vector<int> B(A.size(), -1);
    for (int i = 0; i < A.size(); i++)
    {
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    int l = -1;
    for (int i = 0; i < B.size(); i++)
    {
        if (A[i] != B[i])
        {
            l = i;
            break;
        }
    }
    if (l == -1)
        return {-1};
    int r = -1;
    for (int i = B.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
        {
            r = i;
            break;
        }
    }
    res = {l, r};
    return res;
}
