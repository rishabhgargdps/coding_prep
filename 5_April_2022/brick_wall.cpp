class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<vector<int>>c_w(wall.size());
        int res = INT_MAX;
        int partition = 1;
        int t_w = 0;
        int cross = 0;
        for(int i=0; i<wall[0].size(); i++) {
            t_w += wall[0][i];
        }
        for(int i=0; i<c_w.size(); i++) {
            c_w[i].push_back(wall[i][0]);
        }
        for(int i=0; i<wall.size(); i++) {
            for(int j=1; j<wall[i].size(); j++) {
                c_w[i].push_back(c_w[i][j-1] + wall[i][j]);
            }
        }
        for(int partition = 1; partition < t_w; partition++) {
            cross = 0;
            for(int i=0; i<wall.size(); i++) {
                if(!binary_search(c_w[i].begin(), c_w[i].end(), partition)) cross++;
            }
            cout << cross << endl;
            res = min(res, cross);
        }
        return res == INT_MAX ? wall.size() : res;
    }
};