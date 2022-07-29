class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int>m;
        int res = 0;
        for(int i=0; i<grid.size(); i++) {
            string temp = "";
            for(int j=0; j<grid[0].size(); j++) {
                temp += to_string(grid[i][j]) + " ";
            }
            m[temp]++;
        }
        for(int i=0; i<grid[0].size(); i++) {
            string temp = "";
            for(int j=0; j<grid.size(); j++) {
                temp += to_string(grid[j][i]) + " ";
            }
            res += m[temp];
        }
        return res;
    }
};