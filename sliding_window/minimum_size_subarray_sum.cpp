//this implements the solution when sum == target and not the greater than case
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window technique
        int begin=0, last=0, curr_sum=0, min_length=INT_MAX, window;
        while(last<nums.size()) {
            curr_sum+=nums[last];
            while(curr_sum>target) {
                curr_sum-=nums[begin];
                begin++;
            }
            window = last-begin+1;
            cout << curr_sum << " "<< " "<<begin <<" "<<last <<" "<< window << endl;
            if(curr_sum==target) {
                min_length = min(min_length, last-begin+1);
            }
            last++;
        }
        return min_length==INT_MAX?0:min_length;
    }
};

//the generic solution
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start = 0 ;
        int end = 1;
        int win ;
        int sum=0;
        int n = nums.size();
        
        int res = INT_MAX;
        win = 1;
        sum = nums[start];
      
        while(start<end && end<n )
        {     
            while(end<n && sum < target)
            {
                sum = sum + nums[end];
                end++;
                win++;
            }    
            while(start<end && sum >= target)
            {   
                res = min(res , win);   
                sum = sum - nums[start];
                start++;
                win--;            
            }    
        }
		
        if(res == INT_MAX)
        return 0;
        else
        return res;
    }
};