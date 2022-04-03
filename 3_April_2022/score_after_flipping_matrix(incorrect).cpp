class Solution {
public:
    bool swap_req(vector<int>& v) {
        if(v[0] == 1) return false;
        return true;
    }
    bool swap_req_col(vector<int>& v) {
        int n = v.size();
        int count = 0;
        for(int i=0; i<n; i++) {
            if(v[i]) count++;
        }
        return count <= n/2;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //row swapping
        for(int i=0; i<m; i++) {
            vector<int>temp;
            for(int j=0; j<n; j++) {
                temp.push_back(grid[i][j]);
            }
            if(swap_req(temp)) {
                for(int j=0; j<n; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        //column swapping
        for(int i=n/2; i<n; i++) {
            vector<int>temp;
            for(int j=0; j<m; j++) {
                temp.push_back(grid[j][i]);
            }
            if(swap_req_col(temp)) {
                for(int j=0; j<m; j++) {
                    grid[j][i] = !grid[j][i];
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        int res = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                res += pow(2, n-1-j)*grid[i][j];
            }
        }
        return res;
    }
};