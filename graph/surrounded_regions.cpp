class Solution
{
public:
    void DFS(vector<vector<char>> &board, int i, int j)
    {
        int v = board.size();
        int w = board[0].size();
        if (i < 0 || i >= v || j < 0 || j >= w || board[i][j] != 'O')
            return;
        board[i][j] = '*';
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto d : dir)
        {
            int x1 = i + d[0];
            int x2 = j + d[1];
            DFS(board, x1, x2);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        //explore all the Os in the first row
        int v = board.size();
        int w = board[0].size();
        for (int i = 0; i < w; i++)
        {
            if (board[0][i] == 'O')
            {
                DFS(board, 0, i);
            }
            if (board[v - 1][i] == 'O')
            { //explore the last row
                DFS(board, v - 1, i);
            }
        }
        //explore the first column
        for (int i = 0; i < v; i++)
        {
            if (board[i][0] == 'O')
            {
                DFS(board, i, 0);
            }
            if (board[i][w - 1] == 'O')
            { //explore the last column
                DFS(board, i, w - 1);
            }
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '*')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};