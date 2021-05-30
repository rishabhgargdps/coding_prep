#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOrders(int n) {
        int res=1;
        long long m=pow(10,9)+7;
        for (int i=2; i<=n; i++) {
            res=((((res)%m*i%m)%m)*(((2*i)%m-1)%m))%m;
        }
        return res%m;
    }
};