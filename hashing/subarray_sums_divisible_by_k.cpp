class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //sliding window + hashing
        //curr_sum%k has to be searched since curr_sum - curr_sum%k will be divisible by k
        //this code detects only positive sums divisible by k
        unordered_map<int, int>m;
        int begin = 0;
        int curr_sum = 0;
        int res = 0;
        for (int end=0; end<nums.size(); end++) {
            curr_sum += nums[end];
            if(curr_sum%k == 0) {
                res++;
            }
            if(m.find(curr_sum%k)!=m.end()) {
                res+=m[curr_sum%k];
                cout << end << endl;
            }
            m[curr_sum]++;
        }
        return res;
    }
};

//correct solution
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //sliding window + hashing
        //keep track of remainders. If same remainder, then the middle portion is divisible by k
        vector<int>rem(k,0);
        int curr_sum = 0;
        int res = 0;
        for (int end=0; end<nums.size(); end++) {
            curr_sum += nums[end];
            rem[((curr_sum%k)+k)%k]++;
        }
        for(int i=1; i<rem.size(); i++) {
            res+=rem[i]*(rem[i]-1)/2;
        }
        res+=rem[0]*(rem[0]-1)/2 + rem[0];
        return res;
    }
};