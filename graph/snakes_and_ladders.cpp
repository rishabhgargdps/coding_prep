class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        if (board.size() == 0)
            return 0;
        int n = board.size();
        vector<bool> visited(n * n + 1, false);

        queue<int> q;
        q.push(1);

        int moves = 0;
        int minimum = n * n;
        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int cur = q.front();
                q.pop();
                if (cur == n * n)
                {
                    minimum = min(minimum, moves);
                }

                for (int j = 1; j <= 6; j++)
                {
                    if (j + cur > n * n)
                        break;

                    if (!visited[j + cur])
                    {
                        visited[j + cur] = true;
                        int row = n - (j + cur - 1) / n - 1;

                        int col = ((n - row) % 2 != 0) ? (j + cur - 1) % n : n - (j + cur - 1) % n - 1;

                        if (board[row][col] == cur)
                            continue;
                        if (board[row][col] == -1)
                        {
                            q.push(j + cur);
                        }
                        else
                        {
                            q.push(board[row][col]);
                        }
                    }
                }
            }

            moves++;
        }

        return minimum == n * n ? -1 : minimum;
    }
};