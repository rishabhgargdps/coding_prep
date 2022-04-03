class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = 0;
        int maxlen = 0;
        for(auto rectangle: rectangles) {
            maxlen = max(min(rectangle[0], rectangle[1]), maxlen);
        }
        for(auto rectangle: rectangles) {
            if(min(rectangle[0], rectangle[1]) >= maxlen) res++;
        }
        return res;
    }
};