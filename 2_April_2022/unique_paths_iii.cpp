class Solution {
public:
    int res = 0;
    vector<vector<int>>dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    bool check(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if(row >= 0 && row < grid.size() && col >=0 && col < grid[0].size() && grid[row][col] != -1 && !visited[row][col]) return true;
        return false;
    }
    bool all_visited(vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        for(int i=0; i<visited.size(); i++) {
            for(int j=0; j<visited[0].size(); j++) {
                if(grid[i][j] == 0 && !visited[i][j]) return false;
            }
        }
        return true;
    }
    void solve(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if(grid[row][col] == 2) {
            if(all_visited(grid, visited)) res++;
            return;
        }
        visited[row][col] = true;
        //Recursive step
        for(auto d : dir) {
            int curr_row = row + d[0];
            int curr_col = col + d[1];
            if(check(grid, visited, curr_row, curr_col)) solve(grid, visited, curr_row, curr_col);
        }
        visited[row][col] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false));
        int top = 0, left = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    top = i;
                    left = j;
                    break;
                }
            }
        }
        solve(grid, visited, top, left);
        return res;
    }
};