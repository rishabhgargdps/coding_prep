class Solution {
public:
    int findPivot(vector<int>& nums, int low, int high) {
        int mid = low + (high-low)/2;
        if(low>=high) return high;
        else if(nums[mid]>nums[high]) return findPivot(nums,mid+1,high);
        else return findPivot(nums,low,mid);
    }
    int binarySearch(vector<int>nums, int low, int high, int target) {
        int mid = low + (high-low)/2;
        if (low > high) return -1; 
        else if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return binarySearch(nums, low, mid-1, target);
        else if (nums[mid] < target) return binarySearch(nums, mid+1, high, target);
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums, 0, nums.size()-1);
        cout << pivot;
        int search_left = binarySearch(nums, 0, pivot, target);
        int search_right = binarySearch(nums, pivot, nums.size()-1, target);
        if(search_left!=-1) return search_left;
        return search_right;
    }
};