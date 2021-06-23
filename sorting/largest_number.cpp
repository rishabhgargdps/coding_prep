string Solution::largestNumber(const vector<int> &A)
{
    sort(A.begin(), A.end(), [](int &x, int &y)
         {
             string temp1 = to_string(x);
             string temp2 = to_string(y);
             return temp1 + temp2 < temp2 + temp1;
         });
    string res = "";
    for (int i = 0; i < A.size(); i++)
    {
        res += to_string(A[i]);
    }
    return res;
}

