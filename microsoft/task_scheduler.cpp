class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> char_map(26, 0);
        for (char c : tasks)
        {
            char_map[c - 'A']++;
        }
        sort(char_map.begin(), char_map.end());
        int max_val = char_map[25] - 1;
        int slots = max_val * n;
        for (int i = 24; i >= 0; i--)
        {
            slots -= min(char_map[i], max_val);
        }
        return tasks.size() + (slots > 0 ? slots : 0);
    }
};