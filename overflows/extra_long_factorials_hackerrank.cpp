#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void mult(vector<int>&arr, int i) {
    int ans=0, rem_digits=0;
    for (int j=0; j<arr.size();j++) {
        ans = arr[j]*i+rem_digits;
        arr[j] = ans%10;
        rem_digits=ans/10;
    }
    while (rem_digits!=0) {
        arr.push_back(rem_digits%10);
        rem_digits/=10;
    }
}

int main() {
    vector<int>arr(1,1);
    int n;
    cin >> n;
    int i;
    for (i=2;i<=n;i++) {
        mult(arr,i);
    }
    n=arr.size();
    for (int i=n-1;i>=0;i--) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}