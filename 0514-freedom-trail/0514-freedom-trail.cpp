class Solution {
public:
    //CANNOT BE SOLVED WITH TABULATION SINCE THERE ARE MANY INVALID/IMPOSSIBLE STATES HERE
    int solve(string &ring, string &key, int curr_index, int key_index, vector<vector<int>>& dp) {
        if(key_index == key.length()) return 0;
        if(dp[curr_index][key_index] != -1) return dp[curr_index][key_index];
        //increasing i
        int i=curr_index;
        int steps = 0;
        while(ring[i] != key[key_index]) {
            steps++;
            i++;
            if(i == ring.length()) i = 0;
        }
        int minimum = steps+1+solve(ring, key, i, key_index+1, dp);
        //decreasing i
        i = curr_index;
        steps = 0;
        while(ring[i] != key[key_index]) {
            steps++;
            i--;
            if(i == -1) i = ring.length()-1;
        }
        minimum = min(minimum, steps+1+solve(ring, key, i, key_index+1, dp));
        return dp[curr_index][key_index] = minimum;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(ring.length(), vector<int>(key.length(), -1));
        return solve(ring, key, 0, 0, dp);
    }
};