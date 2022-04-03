class BrowserHistory {
public:
    stack<string>stk;
    stack<string>stk2;
    BrowserHistory(string homepage) {
        stack<string>stk_temp;
        stack<string>stk_temp2;
        swap(stk, stk_temp);
        swap(stk2, stk_temp2);
        stk.push(homepage);
    }
    
    void visit(string url) {
        stk.push(url);
        stack<string>stk_temp2;
        swap(stk2, stk_temp2);
    }
    
    string back(int steps) {
        int n = stk.size();
        steps = min(n, steps);
        while(min(n, steps) > 0) {
            stk2.push(stk.top());
            stk.pop();
            n--;
            steps--;
        }
        return stk.size() > 0 ? stk.top() : stk2.top();
    }
    
    string forward(int steps) {
        int n = stk2.size();
        steps = min(n, steps);
        while(min(n, steps) > 0) {
            stk.push(stk2.top());
            stk2.pop();
            n--;
            steps--;
        }
        return stk.size() > 0 ? stk.top() : stk2.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */