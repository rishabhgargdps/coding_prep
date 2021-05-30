#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        map <char, int> freq;
        for (int i=0; i<s.size(); i++) {
            freq[s[i]]++;
        }
        sort (s.begin(), s.end(), [=](char &a, char &b){
            if (freq.find(a)->second!=freq.find(b)->second) return freq.find(a)->second>freq.find(b)->second;
            else return a<b;
        });
        return s;
    }
};
int main () {
    Solution s;
    string res = s.frequencySort("tree");
    cout << res << endl;
    return 0;
}