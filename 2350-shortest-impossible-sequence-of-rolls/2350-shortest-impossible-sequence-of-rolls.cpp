class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_map<int, int>m;
        int count = 0, res = 0;
        for(int i : rolls) {
            m[i]++;
            if(m[i] == 1) count++;
            if(count == k) {
                res++;
                m.clear();
                count = 0;
            }
        }
        return res+1;
    }
};