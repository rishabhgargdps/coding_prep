class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res(n);
        for(int i=0; i<n; i++) {
            res[i] = -n/2+i;
        }
        if(!(n%2)) res[n-1]+=n/2;
        return res;
    }
};