#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<pair<int, int>>stk;
    /** initialize your data structure here. */
    MinStack() {
        // stack<pair<int, int>>stk;
    }
    
    void push(int val) {
        int min_value=INT_MAX;
        if(stk.empty()) min_value=val;
        else if(!stk.empty()) min_value = min(val, getMin());
        pair<int,int> p(min_value, val);
        stk.push(p);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().second;
    }
    
    int getMin() {
        return stk.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */