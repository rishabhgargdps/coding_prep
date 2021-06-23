#include <iostream>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), -1);
        stack<int> stk;
        int max_area = 0;
        int area;
        for (int i = 0; i < heights.size(); i++)
        {
            //computing the left array
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            if (stk.empty())
                left[i] = 0;
            else
                left[i] = stk.top() + 1;
            stk.push(i);
        }
        stack<int> stk2; //to clear the stack
        swap(stk, stk2);
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            //computing the right array
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            if (stk.empty())
                right[i] = heights.size() - 1;
            else
                right[i] = stk.top() - 1;
            stk.push(i);
        }
        for (int i = 0; i < heights.size(); i++)
        {
            area = (right[i] - left[i] + 1) * heights[i];
            max_area = max(area, max_area);
        }
        return max_area;
    }
};

int Solution::largestRectangleArea(vector<int> &A)
{
    stack<int> stk;
    //left bound preprocessing
    vector<int> left(A.size(), 0);
    vector<int> right(A.size(), A.size() - 1);
    for (int i = 0; i < A.size(); i++)
    {
        while (!stk.empty() && A[stk.top()] >= A[i])
        {
            stk.pop();
        }
        if (!stk.empty())
            left[i] = stk.top() + 1;
        stk.push(i);
    }
    stack<int> stk2;
    swap(stk, stk2); //clear the stack
    for (int i = A.size() - 1; i >= 0; i--)
    {
        while (!stk.empty() && A[stk.top()] >= A[i])
        {
            stk.pop();
        }
        if (!stk.empty())
            right[i] = stk.top() - 1;
        stk.push(i);
    }
    int area = 0;
    int max_area = 0;
    for (int i = 0; i < A.size(); i++)
    {
        area = (right[i] - left[i] + 1) * A[i];
        max_area = max(max_area, area);
    }
    return max_area;
}
