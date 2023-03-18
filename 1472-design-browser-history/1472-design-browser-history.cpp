class BrowserHistory {
public:
    stack<string>stk1;
    stack<string>stk2;
    BrowserHistory(string homepage) {
        stk1.push(homepage);
    }
    
    void visit(string url) {
        stk1.push(url);
        stack<string>stk3;
        swap(stk2, stk3);
    }
    
    string back(int steps) {
        while(stk1.size() > 1 && steps > 0) {
            steps--;
            string top = stk1.top();
            stk1.pop();
            stk2.push(top);
        }
        return stk1.top();
    }
    
    string forward(int steps) {
        while(stk2.size() > 0 && steps > 0) {
            steps--;
            string top = stk2.top();
            stk2.pop();
            stk1.push(top);
        }
        return stk1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */