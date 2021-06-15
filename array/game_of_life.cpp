class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>dir = {{-1,-1},{-1,0},{0,-1},{0,1},{-1,1},{1,1},{1,0},{1,-1}};
        int m = board.size();
        int n = board[0].size();
        int count;
        vector<vector<int>>res(m, vector<int>(n,-1));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                count = 0;
                for(vector<int> d: dir) {
                    int p = i+d[0];
                    int q = j+d[1];
                    if(p>=0 && q>=0 && p<m && q<n && board[p][q]==1) {
                        count++;
                    }
                }
                if(board[i][j]==1) {
                    res[i][j]=1;
                    if(count<2 || count>3) {
                        res[i][j]=0;
                    }
                }
                else if(board[i][j]==0) {
                    res[i][j]=0;
                    if(count==3) {
                        res[i][j]=1;
                    }
                }
            }
        }
        for(int i=0; i<m;i++) {
            for(int j=0; j<n;j++) {
                board[i][j] = res[i][j];
            }
        }
    }
};

//inplace solution
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>dir = {{-1,-1},{-1,0},{0,-1},{0,1},{-1,1},{1,1},{1,0},{1,-1}};
        int m = board.size();
        int n = board[0].size();
        int count;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                count = 0;
                for(vector<int> d: dir) {
                    int p = i+d[0];
                    int q = j+d[1];
                    if(p>=0 && q>=0 && p<m && q<n && (board[p][q]==1 || board[p][q]==2)) {
                        count++;
                    }
                }
                if(board[i][j]==1 && (count<2 || count>3)) {
                    board[i][j]=2;
                }
                else if(board[i][j]==0 && count==3) {
                    board[i][j]=3;
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                board[i][j]=board[i][j]%2;
            }
        }
    }
};