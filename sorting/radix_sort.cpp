//used to sort non-ascii strings and large integers 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxNumber (const vector<int>&v) {
    int max_number=INT_MIN;
    for (int i : v) {
        max_number = max(max_number, i);
    }
    return max_number;
}
//general purpose counting sort algorithm (here: for numbers)
void counting_sort(vector<int>&v, int exp){
    vector<int>count(10,0);
    for (int i=0; i<v.size(); i++) {
        count[v[i]/exp%10]++;
    }
    //cumulative count array
    for (int i=1; i<v.size();i++) {
        count[i]+=count[i-1];
    }
    vector<int>output(v.size(),0);
    for (int i=v.size()-1; i>=0; i--) {
        output[count[v[i]/exp%10]-1] = v[i];
        count[v[i]/exp%10]--;
    }
    for (int i=0; i<v.size(); i++) {
        v[i]=output[i];
    }
}

void radix_sort (vector<int>&v) {
    int max_number = maxNumber(v), exp = 1;
    while (max_number > 0) {
        counting_sort(v, exp);
        exp*=10;
        max_number/=10;
    }
}

void print(const vector<int>&v) {
    for (int i =0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
}
    
int main() {
    vector<int>v={1,2,3,344,4,35,6};
    radix_sort(v);
    print(v);
    return 0;
}