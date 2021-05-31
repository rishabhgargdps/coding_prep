#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int digit_sum(int n)
{
    int sum = 0;
    while (n!=0) {
        sum+=n%10;
        n/=10;
    } 
    return sum;
}

int digit_sum(string n) {
    int sum = 0;
    for (char c : n) {
        sum+=(c-'0');
    }
    return sum;
}

int super_digit(int n) {
    while(n>9) {
        n = digit_sum(n);
    }
    return n;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;
    int res = digit_sum(n);
    cout << super_digit(k*res) << endl;
    return 0;
}