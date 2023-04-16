class Solution {
public:
    int countDigitOne(int n) {
        if(n < 20) {
            int count = 0;
            for(int i=1; i<=n; i++) {
                string temp = to_string(i);
                for(int k=0; k<temp.length(); k++) {
                    if(temp[k] == '1') count++;
                }
            }
            return count;
        }
        int constraint = 9; //from 10^0 to 10^8
        vector<int>dp(constraint);
        
        //from 0 to 9: 1
        //from 10 to 19: (from 0 to 9) + (19-10+1)
        //from 20 to 99: (from 0 to 9)*(9-2+1)
        //from 100 to 199: (from 0 to 99) + (199-100+1)
        //from 200 to 999: (from 0 to 99)*(9-2+1)
        //from 1000 to 1999: (from 0 to 999) + (1999-1000+1)
        //from 2000 to 9999: (from 0 to 999)*(9-2+1)
        //dp[0] = 1: from 0 to 9
        //dp[1] = 10+dp[0] + dp[0]*8: from 10 to 99
        //dp[2] = 100+dp[1] + dp[1]*8: from 100 to 999
        //dp[n] = 10^n + 9*dp[n-1]

        dp[0] = 1;
        for(int i=1; i<dp.size(); i++) {
            dp[i] = pow(10, i) + 10*dp[i-1];
        }
        string temp = to_string(n);
        int power = temp.length()-2;
        
        int count = 0;
        for(int i=0; i<temp.length()-1; i++) {
            if(temp[i] > '1') count += (temp[i]-'0')*(dp[power])+pow(10, power+1);
            else if(temp[i] == '1') {
                count += (temp[i]-'0')*dp[power]+stoi(temp.substr(i+1))+1;
                cout << dp[power] << endl;
            }
            power--;
        }
        if(temp.back() == '0') return count;
        return count+1;
    }
};