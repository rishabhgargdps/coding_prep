#include <iostream>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1) return 1;
        bool inc = arr[0] < arr[1];
        int count;
        count = (arr[0]!=arr[1])?2:1;
        int maxele = count;
        for(int i=1; i<arr.size()-1; i++) {
            if((inc && arr[i]>arr[i+1]) || (!inc && arr[i]<arr[i+1])) {
                count++;
                maxele = max(maxele, count);
            }
            else {
                count = (arr[i]!=arr[i+1])?2:1;
            }
            inc = arr[i]<arr[i+1];
        }
        return maxele;
    }
};