#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0, n=columnTitle.size(), prod=1;
        for (int i=n-1;i>=0;i--) {
            res+=(columnTitle[i]-'A'+1)*prod;
            prod*=26;
        }
        return res;
    }
    
};

int main() {
    Solution s;
    int res = s.titleToNumber("A");
    cout << res;
}