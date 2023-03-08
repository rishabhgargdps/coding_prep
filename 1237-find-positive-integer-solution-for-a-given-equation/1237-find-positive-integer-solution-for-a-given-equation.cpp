/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>res;
        for(int i=1; i<=1000; i++) {
            int left = 1, right = 1000;
            while(left <= right) {
                int mid = left + (right-left)/2;
                if(customfunction.f(i, mid) == z) {
                    res.push_back({i, mid});
                    break;
                }
                else if(customfunction.f(i, mid) < z) left = mid+1;
                else right = mid-1;
            }
        }
        return res;
    }
};