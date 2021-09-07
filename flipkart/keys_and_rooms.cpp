class Solution
{
public:
    bool res = false;

    void dfs(vector<vector<int>> &rooms, int key, unordered_set<int> &visited)
    {
        //Recursive step
        visited.insert(key);
        //Base cases
        if (visited.size() == rooms.size())
        {
            res = true;
            return;
        }
        for (int i = 0; i < rooms[key].size(); i++)
        {
            if (visited.find(rooms[key][i]) == visited.end())
                dfs(rooms, rooms[key][i], visited);
        }
        visited.erase(key);
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        res = false;
        unordered_set<int> visited;
        dfs(rooms, 0, visited);
        return res;
    }
};

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        unordered_set<int> keys;
        keys.insert(0);
        for (int i = 0; i < rooms.size(); i++)
        {
            if (keys.find(i) == keys.end())
                return false;
            for (int j = 0; j < rooms[i].size(); j++)
            {
                keys.insert(rooms[i][j]);
            }
        }
        return true;
    }
};