class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        //two conditions: either start == end || start != end && last facing direction != north
        int x_coordinate = 0, y_coordinate = 0;
        char curr_dir = 'N';
        for (int i = 0; i < instructions.size(); i++)
        {
            if (instructions[i] == 'G')
            {
                if (curr_dir == 'N')
                {
                    y_coordinate++;
                }
                else if (curr_dir == 'L')
                {
                    x_coordinate--;
                }
                else if (curr_dir == 'R')
                {
                    x_coordinate++;
                }
                else if (curr_dir == 'S')
                {
                    y_coordinate--;
                }
            }
            else if (instructions[i] == 'L')
            {
                if (curr_dir == 'N')
                {
                    curr_dir = 'L';
                }
                else if (curr_dir == 'L')
                {
                    curr_dir = 'S';
                }
                else if (curr_dir == 'R')
                {
                    curr_dir = 'N';
                }
                else if (curr_dir == 'S')
                {
                    curr_dir = 'R';
                }
            }
            else if (instructions[i] == 'R')
            {
                if (curr_dir == 'N')
                {
                    curr_dir = 'R';
                }
                else if (curr_dir == 'L')
                {
                    curr_dir = 'N';
                }
                else if (curr_dir == 'R')
                {
                    curr_dir = 'S';
                }
                else if (curr_dir == 'S')
                {
                    curr_dir = 'L';
                }
            }
        }
        if (x_coordinate == 0 && y_coordinate == 0)
            return true;
        if (curr_dir != 'N')
            return true;
        return false;
    }
};