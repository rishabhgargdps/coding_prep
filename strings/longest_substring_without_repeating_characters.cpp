#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_index(256,-1);
        int size;
        int max_size = 0;
        int i=0, j=0;
        for(j=0; j<s.length();j++) {
            if(last_index[s[j]] != -1 && last_index[s[j]] >= i) {
                i = ++last_index[s[j]];
            }
            last_index[s[j]] = j;
            size = j-i+1;
            max_size = max(max_size, size);
        }
        return max_size;
    }
};