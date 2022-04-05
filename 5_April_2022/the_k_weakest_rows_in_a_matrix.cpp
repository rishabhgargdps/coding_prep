class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>>temp(m);
        for(int i=0; i<m; i++) {
            if(mat[i][0] == 0) {
                temp[i] = {0, i};
                continue;
            }
            int left = 0, right = n - 1;
            while(left < right) {
                int mid = left + (right - left)/2;
                if(mat[i][mid] == 0) right = mid - 1;
                else if(mid + 1 < n && mat[i][mid+1] == 0) {
                    left = mid;
                    break;
                }
                else left = mid + 1;
            }
            temp[i] = {left+1, i};
        }
        sort(temp.begin(), temp.end());
        vector<int>res;
        for(int i=0; i<k; i++) {
            res.push_back(temp[i].second);
        }
        return res;
    }
};