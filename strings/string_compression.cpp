#include <iostream>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int start=0,i=0,count=1;
        for(int i=0; i<chars.size()-1; i++) {
            if(chars[i]==chars[i+1]) {
                count++;
            }
            else {
                chars[start++] = chars[i];
                if(count>1) {
                    string temp = to_string(count);
                    for(int k=0;k<temp.length();k++) {
                        chars[start++] = temp[k];
                    }
                }
                count=1;
            }
        }
        chars[start++] = chars[chars.size()-1];
        if(count>1) {
            string temp = to_string(count);
            for(int k=0;k<temp.length();k++) {
                chars[start++] = temp[k];
            }
        }
        return start;
    }
};