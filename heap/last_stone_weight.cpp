#include <iostream>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxq(stones.begin(), stones.end());
        while(maxq.size()>1) {
            int y = maxq.top();
            maxq.pop();
            int x = maxq.top();
            maxq.pop();
            if(y-x) maxq.push(y-x);
        }
        if(maxq.size()) return maxq.top();
        return 0;
    }
};