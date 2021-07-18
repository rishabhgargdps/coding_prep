// O(m+n) time complexity
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(m + n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                res[k++] = nums1[i++];
            }
            else
                res[k++] = nums2[j++];
        }
        while (i < m)
        {
            res[k++] = nums1[i++];
        }
        while (j < n)
        {
            res[k++] = nums2[j++];
        }
        int index = (m + n) / 2;
        if ((m + n) % 2)
            return res[index];
        return (double(res[index - 1]) + res[index]) / 2;
    }
};

//O(log(m+n)) time complexity
class Solution
{
public:
    double findMedian(vector<int> &nums1, vector<int> &nums2, int start_a, int end_a, int start_b, int end_b)
    {
        //Base case
        if (start_a - end_a == 1 && start_b - end_b == 1)
            return (1.0 * (max(start_a, start_b)) + min(end_a, end_b)) / 2;
        //Recursive step
        int m1_index = (start_a + end_a) / 2;
        int m2_index = (start_b + end_b) / 2;
        int m2 = nums2[m2_index];
        int m1 = nums1[m1_index];
        if (m1 == m2)
            return m1;
        else if (m1 < m2)
        {
            start_a = m1_index;
            end_b = m2_index;
        }
        else
        {
            start_b = m2_index;
            end_a = m1_index;
        }
        return findMedian(nums1, nums2, start_a, start_b, end_a, end_b);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        return findMedian(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1);
    }
};