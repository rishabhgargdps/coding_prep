class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        unordered_map<int, int>odd;
        unordered_map<int, int>even;
        for(int i=0; i<nums.size(); i+=2) {
            odd[nums[i]]++;
        }
        for(int i=1; i<nums.size(); i+=2) {
            even[nums[i]]++;
        }
        vector<pair<int, int>>v1, v2;
        for(auto itr : odd) {
            v1.push_back({itr.second, itr.first});
        }
        for(auto itr : even) {
            v2.push_back({itr.second, itr.first});
        }
        sort(v1.begin(), v1.end(), [](pair<int, int>a, pair<int, int>b){
           return a.first > b.first; 
        });
        sort(v2.begin(), v2.end(), [](pair<int, int>a, pair<int, int>b){
            return a.first > b.first;
        });
        if(v1[0].second != v2[0].second) return (n+1)/2 - v1[0].first + n/2 - v2[0].first;
        else {
            int ans = (n+1)/2 + n/2;
            if(v1.size() == 1 && v2.size() == 1) return ans - max(v1[0].first, v2[0].first);
            if(v1.size() == 1) return ans - v1[0].first - v2[1].first;
            if(v2.size() == 1) return ans - v1[1].first - v2[0].first;
            return ans - max(v1[0].first+v2[1].first, v2[0].first+v1[1].first);
        }
    }
};

// INCORRECT--
// class Solution {
// public:
//     int minimumOperations(vector<int>& nums) {
//         unordered_map<int, int>m_even;
//         unordered_map<int, int>m_odd;
//         int maximum_even = 0, maximum_odd = 0, i_even = 0, i_odd = 1;
//         for(int i=0; i<nums.size(); i+=2) {
//             m_even[nums[i]]++;
//             if(maximum_even < m_even[nums[i]]) {
//                 i_even = nums[i];
//                 maximum_even = m_even[nums[i]];
//             }
//         }
//         for(int i=1; i<nums.size(); i+=2) {
//             m_odd[nums[i]]++;
//             if(maximum_odd < m_odd[nums[i]]) {
//                 i_odd = nums[i];
//                 maximum_odd = m_odd[nums[i]];
//             }
//         }
//         if(i_even == i_odd) {
//             priority_queue<vector<int, int>>odd;
//             priority_queue<vector<int, int>>even;
//             for(auto itr != maximum_odd.begin(); itr != maximum_odd.end(); ++itr) {
//                 odd.push({itr->second, itr->first});
//             }
//             for(auto itr != maximum_even.begin(); itr != maximum_even.end(); ++itr) {
//                 even.push({itr->second, itr->first});
//             }
//             while(!odd.empty() && !even.empty() && odd.top()[1] == even.top()[1]) {
//                 odd.pop();
//                 even.pop();
//             }
            
//         }
//         return nums.size()-(maximum_odd + maximum_even);
//     }
// };