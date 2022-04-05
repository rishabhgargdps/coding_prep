class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int even_pointer = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] % 2 == 0 && i != even_pointer) {
                swap(nums[i], nums[even_pointer]);
                even_pointer++;
                i--;
            }
        }
        return nums;
    }
};