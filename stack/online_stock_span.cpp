#include<iostream>
using namespace std;
class StockSpanner {
public:
    stack<pair<int,int>>stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ct=1;
        while(!stk.empty() && stk.top().first<=price) {
            ct+=stk.top().second;
            stk.pop();
        }
        stk.push({price, ct});
        return ct;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */