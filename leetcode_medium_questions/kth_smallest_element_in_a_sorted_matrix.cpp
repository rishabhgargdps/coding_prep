//binary search O(n log n) time
class Solution
{
public:
    int search(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] > target)
                return res;
            if (matrix[i][n - 1] <= target)
            {
                res += n;
                continue;
            }
            int start = 0;
            for (int jump = n / 2; jump >= 1; jump /= 2)
            {
                while (start + jump < n && matrix[i][start + jump] <= target)
                {
                    start += jump;
                }
            }
            res += start + 1;
        }
        return res;
    }

    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int res = search(matrix, mid);
            if (res >= k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};

//min heap
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> pq;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};