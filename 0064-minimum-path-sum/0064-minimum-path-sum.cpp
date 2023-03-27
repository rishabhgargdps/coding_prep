class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if(row == grid.size()-1 && col == grid[0].size()-1) return dp[row][col] = grid[row][col];
        if(row == grid.size()-1) return dp[row][col] = grid[row][col] + solve(grid, row, col+1, dp);
        if(col == grid[0].size()-1) return dp[row][col] = grid[row][col] + solve(grid, row+1, col, dp);
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = grid[row][col] + min(solve(grid, row, col+1, dp), solve(grid, row+1, col, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, 0, 0, dp);
    }
};