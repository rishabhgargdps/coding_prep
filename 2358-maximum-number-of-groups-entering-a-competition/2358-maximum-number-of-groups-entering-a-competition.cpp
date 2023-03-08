class Solution {
public:
    bool valid(int x, int n) {
        if(x*(x+1)/2 <= n) return true;
        return false;
    }
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int left = 1, right = 1000;
        //x*(x+1)/2 <= n
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(valid(mid, n)) left = mid+1;
            else right = mid-1;
        }
        return left-1;
    }
};