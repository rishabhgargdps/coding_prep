class Solution {
public:
    int countSubset(vector<int> &arr, int n, int sum) {
         int dp[n+1][sum+1];

         for(int i=0;i<n+1;i++)
             dp[i][0]=1;

           for(int i=1;i<sum+1;i++)
             dp[0][i]=0;

        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){

                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                else
                   dp[i][j] = dp[i-1][j];

            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if (((sum + target) % 2 != 0) || (target > sum)) 
            return 0;

        int newsum = (target + sum)/2;

       return countSubset(nums, nums.size(), abs(newsum));
    }
};