#include <iostream>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left(heights.size(),-1);
        vector<int>right(heights.size(),-1);
        stack<int>stk;
        int max_area=0;
        int area;
        for(int i=0; i<heights.size(); i++) {
            //computing the left array
            while(!stk.empty() && heights[stk.top()]>=heights[i]) {
                stk.pop();
            }
            if(stk.empty()) left[i]=0;
            else left[i] = stk.top()+1;
            stk.push(i);
        }
        stack<int>stk2; //to clear the stack
        swap(stk, stk2);
        for(int i=heights.size()-1; i>=0; i--) {
            //computing the right array
            while(!stk.empty() && heights[stk.top()]>=heights[i]) {
                stk.pop();
            }
            if(stk.empty()) right[i]=heights.size()-1;
            else right[i] = stk.top()-1;
            stk.push(i);
        }
        for(int i=0; i<heights.size(); i++) {
            area = (right[i]-left[i]+1)*heights[i];
            max_area = max(area, max_area);
        }
        return max_area;
    }
};