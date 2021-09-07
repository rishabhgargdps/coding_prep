class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> res;
        stack<int> stk;
        for (int i = 0; i < asteroids.size(); i++)
        {
            while (!stk.empty() && stk.top() > 0 && asteroids[i] < 0 && stk.top() < abs(asteroids[i]))
            {
                stk.pop();
            }
            if (asteroids[i] < 0 && !stk.empty() && stk.top() > abs(asteroids[i]))
                continue;
            if (asteroids[i] < 0 && !stk.empty() && stk.top() == abs(asteroids[i]))
            {
                stk.pop();
                continue;
            }
            stk.push(asteroids[i]);
        }
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};