#include <iostream>
using namespace std;
class Solution {
public:
    struct compare {
        bool operator() (pair<int, int>p1, pair<int,int>p2) {
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>freq;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> maxq(freq.begin(), freq.end());
        while(k--) {
            res.push_back(maxq.top().first);
            maxq.pop();
        }
        return res;
    }
};