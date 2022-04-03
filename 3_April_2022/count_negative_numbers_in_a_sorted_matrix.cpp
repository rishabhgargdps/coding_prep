class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            int left = 0, right = n-1;
            while(left <= right) {
                int mid = left + (right - left)/2;
                if(grid[i][mid] < 0) right = mid-1;
                else left = mid+1;
            }
            if(left < n && grid[i][left] < 0) res += n - left;
        }
        return res;
    }
};