class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(int num : nums) {
            string temp = to_string(num);
            if(!(temp.length()%2)) res++;
        }
        return res;
    }
};