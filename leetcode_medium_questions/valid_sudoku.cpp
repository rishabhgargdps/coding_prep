class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> s;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int curr_char = board[i][j] - '0';
                    string temp_row = to_string(curr_char) + " found in row " + to_string(i);
                    string temp_col = to_string(curr_char) + " found in col " + to_string(j);
                    string temp_box = to_string(curr_char) + " found in box " + to_string(i / 3) + "-" + to_string(j / 3);
                    if (s.find(temp_row) != s.end() || s.find(temp_col) != s.end() || s.find(temp_box) != s.end())
                        return false;
                    s.insert(temp_row);
                    s.insert(temp_col);
                    s.insert(temp_box);
                }
            }
        }
        return true;
    }
};