#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar=INT_MAX, curr_profit, max_profit=INT_MIN, n=prices.size();
        for (int i=0;i<n;i++) {
            minSoFar = min(prices[i], minSoFar);
            curr_profit = prices[i]-minSoFar;
            max_profit = max(max_profit, curr_profit);
        }
        return max_profit;
    }
};