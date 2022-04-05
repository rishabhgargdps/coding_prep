class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>counter(101, 0);
        for(int i=0; i<heights.size(); i++) {
            counter[heights[i]]++;
        }
        for(int i=1; i<counter.size(); i++) {
            counter[i] += counter[i-1];
        }
        int res = 0;
        for(int i=0; i<heights.size(); i++) {
            int diff = counter[heights[i]]-counter[heights[i]-1];
            if(i < counter[heights[i]-1] || i >= counter[heights[i]]) res++;
        }
        return res;
    }
};