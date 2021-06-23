//wrong solution
bool valid(vector<int> &A, int mid, int high)
{
    int students = 1;
    int curr_sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        curr_sum += A[i];
        if (curr_sum > mid)
        {
            students++;
            curr_sum = A[i];
        }
    }
    return students <= high;
}
int Solution::books(vector<int> &A, int B)
{
    int minimum = INT_MAX, curr_sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        minimum = min(minimum, A[i]);
        curr_sum += A[i];
    }

    int l = minimum;
    int r = curr_sum;
    int res = INT_MAX;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (valid(A, mid, B))
        {
            res = min(res, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}

//correct solution
bool isPossible(long long _Max, int K, vector<int> &Vec)
{

    int _max_ele = *max_element(Vec.begin(), Vec.end());
    if (_max_ele > _Max)
        return false;

    long long Sum = 0;
    int cnt = 1;
    int N = Vec.size();

    for (int i = 0; i < N;)
    {
        if (Sum + ((long long)Vec[i]) > _Max)
        {
            Sum = 0;
            cnt++;
        }
        else
        {
            Sum += ((long long)Vec[i]);
            i++;
        }
    }

    if (cnt <= K)
        return true;
    return false;
}

int Solution::books(vector<int> &Vec, int k)
{
    int N = Vec.size();
    if (N < k)
        return -1;
    long long end = 0;
    long long start = 0;

    for (int i = 0; i < N; ++i)
    {
        end += Vec[i];
    }
    long long ans = INT_MAX;
    // ans *= INT_MAX;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if (isPossible(mid, k, Vec))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}
