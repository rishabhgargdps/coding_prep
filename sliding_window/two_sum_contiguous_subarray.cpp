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