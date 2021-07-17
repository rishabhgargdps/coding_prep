class Solution
{
public:
    vector<int> temp;
    vector<int> original;
    int start = 0;
    int end;
    Solution(vector<int> &nums)
    {
        temp = nums;
        original = nums;
        end = nums.size() - 1;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        end = original.size() - 1;
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        int random = rand() % end;
        swap(temp[random], temp[end]);
        end--;
        if (end == 0)
            end = original.size() - 1;
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

class Solution
{
public:
    vector<int> temp;
    vector<int> original;

    Solution(vector<int> &nums)
    {
        temp = nums;
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int i = temp.size(); i > 0; i--)
        {
            int random = rand() % i;
            swap(temp[i - 1], temp[random]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */