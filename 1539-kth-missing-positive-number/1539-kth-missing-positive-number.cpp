class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //find the numbers missing between a range of array: arr[index] - (index+1);
        int left = 0, right = arr.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            int miss = arr[mid] - (mid+1);
            if(miss < k) left = mid+1;
            else right = mid-1;
        }
        if(right == -1) return k;
        return arr[right] + k - (arr[right] - (right+1));
    }
};