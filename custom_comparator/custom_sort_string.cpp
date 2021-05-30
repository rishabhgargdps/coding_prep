#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string customSortString(string order, string str) {
        sort(str.begin(), str.end(), [=](char &a, char &b){
            return order.find(a)<order.find(b);
        });
    return str;
    }
};
int main() {
    Solution s;
    string res = s.customSortString("cba","abcd");
    cout << res << endl;
    return 0;
}