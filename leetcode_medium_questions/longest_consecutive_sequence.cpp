// O(n^2) : very poor strategy as even sorting the array works better

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int largest = 1;
        int count = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            while (s.find(x - 1) != s.end())
            {
                count++;
                x--;
            }
            largest = max(largest, count);
            count = 1;
        }
        return largest;
    }
};

//O(n) using map
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = 1;
        }
        int largest = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            while (m.find(x - 1) != m.end())
            {
                x--;
                m[nums[i]] += m[x];
                m.erase(x);
            }
            largest = max(largest, m[nums[i]]);
        }
        return largest;
    }
};