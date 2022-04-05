class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        stack<int>stk;
        vector<int>res(arr.size());
        for(int i = arr.size()-1; i>=0; i--) {
            if(!stk.empty()) res[i] = arr[stk.top()];
            while(!stk.empty() && arr[stk.top()] < arr[i]) {
                stk.pop();
            }
            if(!stk.empty()) res[i] = arr[stk.top()];
            if(stk.empty()) stk.push(i);
        }
        res[res.size()-1] = -1;
        return res;
    }
};