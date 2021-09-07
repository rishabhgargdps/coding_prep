class Solution
{
public:
    unordered_set<string> res;
    vector<string> ans;

    void permutations(string tiles, int start, int end)
    {
        if (start == end)
        {
            ans.push_back(tiles);
            // cout << tiles << endl;
            return;
        }
        for (int i = start; i <= end; i++)
        {
            swap(tiles[i], tiles[start]);
            permutations(tiles, start + 1, end);
            swap(tiles[start], tiles[i]);
        }
    }

    void backtrack(string &tiles, string curr, int index)
    {
        //Positive case
        if (index <= tiles.length() && curr.length() > 0)
        {
            res.insert(curr);
            // cout << curr << endl;
        }
        //Negative case
        if (index > tiles.length())
            return;
        //Recursive step
        for (int curr_length = 1; index + curr_length <= tiles.length(); curr_length++)
        {
            string temp = tiles.substr(index, curr_length);
            backtrack(tiles, temp, index + curr_length);
            backtrack(tiles, curr + temp, index + curr_length);
        }
    }

    int numTilePossibilities(string tiles)
    {
        permutations(tiles, 0, tiles.length() - 1);
        for (string tile : ans)
        {
            backtrack(tile, "", 0);
        }
        return res.size();
    }
};

//optimized solution
class Solution
{
public:
    int solve(vector<int> &freq)
    {
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
                continue;
            count++;
            freq[i]--;
            count += solve(freq);
            freq[i]++;
        }
        return count;
    }

    int numTilePossibilities(string tiles)
    {
        vector<int> freq(26, 0);
        for (char c : tiles)
            freq[c - 'A']++;
        return solve(freq);
    }
};