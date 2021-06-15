class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //two pointer approach instead of hashing to make it 2 times faster
        vector<int>res(2,0);
        int i=0;
        int j = numbers.size()-1;
        while(i<j) {
            if(target-numbers[i]==numbers[j]) {
                res[0] = i+1;
                res[1] = j+1;
                return res;
            }
            else if(target-numbers[i]<numbers[j]) {
                j--;
            }
            else i++;
        }
        return res;
    }
};