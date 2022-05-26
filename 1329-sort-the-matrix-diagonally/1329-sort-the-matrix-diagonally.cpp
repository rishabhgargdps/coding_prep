class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int limit = min(mat.size(), mat[0].size());
        for(int i=0; i<mat[0].size(); i++) {
            vector<int>temp;
            for(int j=0; j<limit; j++) {
                if(j < mat.size() && i+j < mat[0].size()) temp.push_back(mat[j][i+j]);
                else break;
            }
            sort(temp.begin(), temp.end());
            for(int j=0; j<limit; j++) {
                if(j < temp.size()) mat[j][i+j] = temp[j];
            }
        }
        for(int i=1; i<mat.size(); i++) {
            vector<int>temp;
            for(int j=0; j<limit; j++) {
                if(i+j < mat.size() && j < mat[0].size()) temp.push_back(mat[i+j][j]);
                else break;
            }
            sort(temp.begin(), temp.end());
            for(int j=0; j<limit; j++) {
                if(j < temp.size()) mat[i+j][j] = temp[j];
            }
        }
        return mat;
    }
};