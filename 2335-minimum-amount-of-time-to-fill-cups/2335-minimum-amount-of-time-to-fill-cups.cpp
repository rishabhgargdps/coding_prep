class Solution {
public:
    int fillCups(vector<int>& amount) {
        int res = 0;
        priority_queue<int>pq(amount.begin(), amount.end());
        while(pq.top() !=0) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x--;
            y--;
            pq.push(x);
            pq.push(y);
            res++;
        }
        return res;
    }
};