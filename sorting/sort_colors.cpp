class Solution {
public:
    void swap(int &x, int &y) {
        int temp=x;
        x=y;
        y=temp;
    }
    void sortColors(vector<int>& nums) {
        int n=nums.size(), red=0, blue=n-1,i=0;
        while (i<=blue) {
            if (nums[i]==0) swap(nums[i++], nums[red++]);
            else if (nums[i]==2) swap(nums[i], nums[blue--]);
            else i++;
        }
    }
};