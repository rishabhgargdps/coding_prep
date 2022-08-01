class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<grid.size(); i++) {
            if(grid[i][i] == 0) return false;
            if(grid[i][n-1-i] == 0) return false;
        }
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(i == j || i == n-1-j) continue;
                if(grid[i][j] != 0) return false;
            }
        }
        return true;
    }
};