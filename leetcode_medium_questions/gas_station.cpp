//wrong but generic solution
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> prefix_sum(gas.size());
        prefix_sum[0] = gas[0] - cost[0];
        for (int i = 1; i < prefix_sum.size(); i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + gas[i] - cost[i];
        }
        int i = 0;
        while (i < prefix_sum.size() && prefix_sum[i] < 0)
        {
            i++;
        }
        int initial_balance = 0;
        int front = i;
        int rear = i;
        while (i < prefix_sum.size())
        {
            initial_balance += gas[i] - cost[i];
            if (initial_balance < 0)
            {
                front = i + 1;
                rear = i + 1;
                initial_balance = 0;
            }
            i++;
        }
        if (rear < prefix_sum.size() && initial_balance + prefix_sum[rear] >= 0)
            return rear - 1;
        return -1;
    }
};

//correct solution
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int n = gas.size();
        int tank = 0;
        int total = 0;
        int consume = 0;
        int index = 0;

        for (int i = 0; i < n; i++)
        {

            consume = gas[i] - cost[i];
            tank += consume;

            if (tank < 0)
            {
                tank = 0;
                index = i + 1;
            }

            total += consume;
        }

        return total >= 0 ? index : -1;
    }
};