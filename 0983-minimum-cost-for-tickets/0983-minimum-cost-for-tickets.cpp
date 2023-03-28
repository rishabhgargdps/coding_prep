class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, const vector<int>& duration, int curr_index, vector<int>& dp) {
        if(curr_index >= days.size()) return 0;
        if(dp[curr_index] != -1) return dp[curr_index];
        int minimum = INT_MAX;
        for(int i=0; i<3; i++) {
            int next_index = lower_bound(days.begin(), days.end(), days[curr_index] + duration[i]) - days.begin();
            minimum = min(minimum, costs[i] + solve(days, costs, duration, next_index, dp));
        }
        return dp[curr_index] = minimum;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = days.size();
        // int n = m * max_element(costs.begin(), costs.end())+1;
        vector<int>dp(m, -1);
        vector<int> duration = {1, 7, 30};
        return solve(days, costs, duration, 0, dp);
    }
};