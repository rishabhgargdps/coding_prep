class Solution
{
public:
    int min_cost = INT_MAX;

    bool check(vector<vector<int>> &special, vector<int> &needs, int special_index)
    {
        for (int i = 0; i < needs.size(); i++)
        {
            if (needs[i] < special[special_index][i])
                return false;
        }
        return true;
    }

    vector<int> subtract(vector<vector<int>> &special, vector<int> &needs, int special_index)
    {
        vector<int> res(needs.size());
        for (int i = 0; i < needs.size(); i++)
        {
            res[i] = needs[i] - special[special_index][i];
        }
        return res;
    }

    void currCost(vector<int> &price, vector<vector<int>> &special, vector<int> &needs, int special_index, int curr_cost)
    {
        //Base case
        if (special_index == special.size())
        {
            for (int i = 0; i < needs.size(); i++)
            {
                curr_cost += needs[i] * price[i];
            }
            min_cost = min(min_cost, curr_cost);
            return;
        }
        //Recursive step
        //exclude
        currCost(price, special, needs, special_index + 1, curr_cost);
        //include
        if (check(special, needs, special_index))
        {
            vector<int> updated_needs = subtract(special, needs, special_index);
            currCost(price, special, updated_needs, special_index, curr_cost + special[special_index][needs.size()]);
        }
    }

    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        min_cost = INT_MAX;
        currCost(price, special, needs, 0, 0);
        return min_cost;
    }
};