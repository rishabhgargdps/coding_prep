#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int n = arr.size();
        if (n==1) return arr[0];
        int count = 1;
        for (int i=1; i<n; i++) {
            if (count>n/4) return arr[i-1];
            else if (arr[i]==arr[i-1]) {
                count++;
            }
            else count = 1;
        }
        if (count>n/4) return arr[n-1];
        return -1;
    }
    int main() {
        vector<int>arr;
        int res = findSpecialInteger(arr);
        cout << res;

    }
};