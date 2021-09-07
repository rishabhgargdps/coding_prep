class TicTacToe
{
public:
    int count = 1;
    /** Initialize your data structure here. */
    array<array<int, 3>, 3> board;
    vector<array<pair<int, int>, 3>> winning_combos = {{{0, 0}, {1, 1}, {2, 2}}, {{0, 0}, {0, 1}, {0, 2}}, {{0, 2}, {1, 1}, {2, 0}}...};
    TicTacToe()
    {
    }
    bool move(int row, int col)
    {
        bool flag = false;
        for (winning_combo : winning_combos)
        {
            int r0 = winning_combo[0].first;
            int r1 = winning_combo[1].first;
            int r2 = winning_combo[2].first;
            int c1 = winning_combo[0].second;
            int c2 = winning_combo[1].second;
            int c3 = winning_combo[2].second;
            if (board[r0][c0] == board[r1][c1] && board[r1][c1] == board[r2][c2])
                cout << "game end" << endl;
            flag = true;
            break;
        }
        if (!flag && board[row][col] == 0)
        {
            board[row][col] = count % 2 ? 1 : 2;
            count++;
            return true;
        }
        else if (!flag && count == board.size() * board[0].size())
        {
            cout << "it's a draw" << endl;
            count = 1;
        }
        return false;
    }
};