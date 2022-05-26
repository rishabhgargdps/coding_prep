class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>res(k, 0);
        unordered_map<int, unordered_set<int>>m;
        for(auto &v : logs) {
            int user = v[0];
            int time = v[1];
            m[user].insert(time);
        }
        unordered_map<int, int>freq;
        for(auto itr = m.begin(); itr != m.end(); itr++) {
            freq[itr->second.size()]++;
        }
        for(auto itr = freq.begin(); itr != freq.end(); ++itr) {
            res[itr->first-1] = itr->second;
        }
        return res;
    }
};