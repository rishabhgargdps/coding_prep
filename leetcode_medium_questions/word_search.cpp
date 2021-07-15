class Solution
{
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool valid(vector<vector<char>> &board, int row, int col)
    {
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size())
            return true;
        return false;
    }

    bool solve(vector<vector<char>> &board, string word, int row, int col, int start, vector<vector<bool>> &visited)
    {
        //Base case
        if (start == word.length())
            return true;
        //Recursive step
        visited[row][col] = true;
        for (auto d : dir)
        {
            int new_row = row + d[0];
            int new_col = col + d[1];
            if (valid(board, new_row, new_col))
            {
                if (board[new_row][new_col] == word[start] && visited[new_row][new_col] == false)
                {
                    if (solve(board, word, new_row, new_col, start + 1, visited))
                        return true;
                }
            }
        }
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (solve(board, word, i, j, 1, visited))
                        return true;
                }
            }
        }
        return false;
    }
};

//please optimize using dp
