class CustomStack {
public:
    int max_ele = 0;
    stack<int>stk1;
    stack<int>stk2;
    CustomStack(int maxSize) {
        stack<int>stk_temp1;
        stack<int>stk_temp2;
        if(stk1.size() == maxSize) swap(stk1, stk_temp1);
        if(stk2.size() == maxSize) swap(stk2, stk_temp2);
        max_ele = maxSize;
    }
    
    void push(int x) {
        if(stk1.size() < max_ele) stk1.push(x);
    }
    
    int pop() {
        if(stk1.size()) {
            int temp = stk1.top();
            stk1.pop();
            return temp;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        while(stk1.size() > k) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        while(stk1.size()) {
            stk2.push(val + stk1.top());
            stk1.pop();
        }
        while(stk2.size()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */