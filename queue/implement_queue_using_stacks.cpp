#include<iostream>
using namespace std;
class MyQueue {
public:
    stack<int>stk1;
    stack<int>stk2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int temp = stk2.top();
        stk2.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(stk2.empty()) {
            while(!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int temp = stk2.top();
        return temp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */