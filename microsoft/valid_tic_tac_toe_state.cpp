class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int count_x = 0, count_o = 0, d1 = 0, d2 = 0;
        vector<int> r(3, 0);
        vector<int> c(3, 0);
        for (string row : board)
        {
            for (char c : row)
            {
                if (c == 'X')
                {
                    count_x++;
                }
                else if (c == 'O')
                {
                    count_o++;
                }
            }
        }
        if (count_x - count_o > 1 || count_x - count_o < 0)
        {
            return false;
        }
        bool won_x = false;
        bool won_o = false;
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[row].length(); col++)
            {
                if (board[row][col] == 'X')
                {
                    r[row]++;
                    c[col]++;
                    if (row == col)
                        d1++;
                    if (row + col == 2)
                        d2++;
                    if (r[row] == 3 || c[col] == 3 || d1 == 3 || d2 == 3)
                        won_x = true;
                }
                else if (board[row][col] == 'O')
                {
                    r[row]--;
                    c[col]--;
                    if (row == col)
                        d1--;
                    if (row + col == 2)
                        d2--;
                    if (r[row] == -3 || c[col] == -3 || d1 == -3 || d2 == -3)
                        won_o = true;
                }
            }
        }
        if (won_x && won_o)
            return false;
        if (count_x == count_o && won_x)
            return false;
        if (count_o == count_x - 1 && won_o)
            return false;
        return true;
    }
};