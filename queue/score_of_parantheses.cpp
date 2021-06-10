#include<iostream>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
        int sum=0;
        int max_size=0, size=0;
        for (int i=0; i<s.length(); i++) {
            if(s[i]=='(') {
                size++;
                max_size = size;
            }
            else if (s[i]==')' && size == max_size) {
                size--;
                sum+=pow(2,size);
            }
            else if (s[i]==')' && size < max_size) {
                size--;
            } 
        }
        return sum;
    }
};