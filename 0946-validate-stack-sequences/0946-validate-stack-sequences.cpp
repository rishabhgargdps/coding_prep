class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>stk;
        int i=0, j=0;
        while(i < pushed.size() && j < popped.size()) {
            if(stk.empty() || stk.top() != popped[j]) {
                stk.push(pushed[i]);
                i++;
            }
            else if(stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        while(j < popped.size()) {
            if(stk.top() != popped[j]) return false;
            stk.pop();
            j++;
        }
        return true;
    }
};