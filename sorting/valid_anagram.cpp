#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s==t)?1:0;
    }
};
int main() {
    Solution s;
    bool res = s.isAnagram("anagram","nagaram");
    return res;
}