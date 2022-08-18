class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>m;
        for(int x : arr) {
            m[x]++;
        }
        vector<pair<int, int>>v;
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            v.push_back({itr->second, itr->first});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int res = 0;
        int n = arr.size();
        int req_size = arr.size()/2;
        for(int i=0; i<v.size(); i++) {
            if(n <= req_size) return res;
            n -= v[i].first;
            res++;
        }
        return res;
    }
};