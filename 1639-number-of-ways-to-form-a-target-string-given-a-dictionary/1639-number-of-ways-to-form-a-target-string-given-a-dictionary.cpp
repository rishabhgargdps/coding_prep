class Solution {
public:
    int mod = 1e9+7;
    int numWays(vector<string>& words, string target) {
        vector<vector<int>>count(words[0].length(), vector<int>(26, 0));
        for(auto &word: words) {
            for(int i=0; i<word.length(); i++) {
                count[i][word[i]-'a']++;
            }
        }
        vector<int>dp(target.length()+1);
        dp[0] = 1;
        for(int curr_index = 0; curr_index < words[0].length(); curr_index++) {
            for(int target_index=target.length()-1; target_index >=0; target_index--) {
                dp[target_index+1] += ((long)dp[target_index]%mod)*(count[curr_index][target[target_index]-'a']%mod)%mod;
                dp[target_index+1] %= mod;
            }
        }
        return dp[target.length()];
    }
};