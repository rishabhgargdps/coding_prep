class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int index = 0, count = 0, curr_num = 1;
        while(true) {
            if(index == arr.size()) break;
            if(curr_num == arr[index]) {
                index++;
                curr_num++;
            }
            else {
                count++;
                if(count == k) return curr_num;
                curr_num++;
            }
        }
        if(count < k) {
            return arr.back() + k-count;
        }
        return -1;
    }
};