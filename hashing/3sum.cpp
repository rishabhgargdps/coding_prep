//TLE error
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        unordered_set<int> m;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (m.find(-nums[i] - nums[j]) != m.end())
                {
                    res.push_back({nums[i], nums[j], *m.find(-nums[i] - nums[j])});
                }
                else
                {
                    m.insert(nums[j]);
                }
            }
            m.clear();
        }
        //remove duplicates
        set<vector<int>> m_temp;
        for (auto &v : res)
        {
            m_temp.insert(v);
        }
        res.clear();
        for (auto itr = m_temp.begin(); itr != m_temp.end(); itr++)
        {
            res.push_back(*itr);
        }
        return res;
    }
};

//TLE error
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        unordered_set<int> m;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (m.find(-nums[i] - nums[j]) != m.end())
                {
                    res.push_back({nums[i], nums[j], *m.find(-nums[i] - nums[j])});
                }
                else
                {
                    m.insert(nums[j]);
                }
            }
            m.clear();
        }
        sort(res.begin(), res.end());
        if (res.size())
        {
            for (int i = 0; i < res.size() - 1; i++)
            {
                if (res[i][0] == res[i + 1][0] && res[i][1] == res[i + 1][1] && res[i][2] == res[i + 1][2])
                {
                    res.erase(res.begin() + i + 1);
                    i--;
                }
            }
        }
        return res;
    }
};

//Correct solution
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int start = i + 1;
            int end = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            while (start < end)
            {
                if (end < nums.size() - 1 && nums[end] == nums[end + 1])
                {
                    end--;
                    continue;
                }
                if (nums[i] + nums[start] + nums[end] == 0)
                {
                    res.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if (nums[i] + nums[start] + nums[end] < 0)
                {
                    start++;
                }
                else if (nums[i] + nums[start] + nums[end] > 0)
                {
                    end--;
                }
            }
        }
        return res;
    }
};