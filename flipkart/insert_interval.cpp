class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int pos = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] > newInterval[0])
            {
                pos = i;
                break;
            }
        }
        int start = 0;
        int end = 0;
        if (pos > 0)
        {
            if (intervals[pos - 1][1] >= newInterval[0])
            {
                start = pos - 1;
                newInterval[0] = intervals[pos - 1][0];
                newInterval[1] = max(newInterval[1], intervals[pos - 1][1]);
                end = pos;
                intervals.erase(intervals.begin() + pos - 1);
            }
        }
        for (int i = pos; i < intervals.size(); i++)
        {
            if (intervals[pos][0] <= newInterval[1])
            {
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                end++;
            }
        }
        intervals.insert(intervals.begin() + pos - 1, newInterval);
        for (int i = pos + 1; i < end; i++)
        {
            intervals.erase(intervals.begin() + i);
        }
        return intervals;
    }
};