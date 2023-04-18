class Solution {
public:
    int solve(vector<int>& boxes, int left, int right, int count, vector<vector<vector<int>>>& dp) {
        if(left > right) return 0;
        if(dp[left][right][count] != -1) return dp[left][right][count];
        int l = left, c = count;
        while(left+1 <= right && boxes[left] == boxes[left+1]) {
            left++;
            count++;
        }
        int ans = (count+1)*(count+1) + solve(boxes, left+1, right, 0, dp);
        for(int m=left+1; m<=right; m++) {
            if(boxes[m] == boxes[left]) {
                ans = max(ans, solve(boxes, m, right, count+1, dp) + solve(boxes, left+1, m-1, 0, dp));
            }
        }
        return dp[l][right][c] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>>dp(boxes.size(), vector<vector<int>>(boxes.size(), vector<int>(boxes.size(), -1)));
        return solve(boxes, 0, boxes.size()-1, 0, dp);
    }
};