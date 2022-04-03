class Solution {
public:
    int findTheWinner(int n, int k) {
        // if(n == 1) return 1;
        // unordered_map<int, vector<int>>m;
        // for(int i=0; i<n; i++) {
        //     m[i] = {(i+n-1)%n, (i+1)%n};
        // }
        // int init_pos = 0;
        // int new_pos;
        // while(m.size() > 1) {
        //     new_pos = (init_pos + k-1)%n;
        //     m[(new_pos-1+m.size())%m.size()][1] = (new_pos+1)%m.size();
        //     m[(new_pos+1)%m.size()][0] = (new_pos-1+m.size())%m.size();
        //     m.erase(new_pos);
        //     init_pos = new_pos;
        // }
        // return m.begin()->first+1;
        queue<int>q;
        for(int i=1; i<=n; i++) {
            q.push(i);
        }
        while(q.size() != 1) {
            for(int i=1; i<=k-1; i++) {
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
            q.pop();
        }
        return q.front();
    }
};