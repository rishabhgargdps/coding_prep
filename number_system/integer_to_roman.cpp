#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        map<int, string>roman = {{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"},{4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{900,"CM"},{400,"CD"}};
        string res="";
        int count=0;
        while (num!=0) {
            if (roman.find(num) != roman.end()) {
                res+=roman.find(num)->second;
                num-=roman.find(num)->first;
            }
            else {
                auto val = (--roman.lower_bound(num));
                res+=val->second;
                count++;
                num-=val->first;
            }
        }
        return res;
    }
};