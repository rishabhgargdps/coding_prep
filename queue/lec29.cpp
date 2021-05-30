#include <bits/stdc++.h>
using namespace std;

void f (int a, int &b) {
    if (b==0) {
        return;
    }
    b--;
    f(a,b);
    cout << a << "," << b << endl;
}
int main () {
    int x=5;
    f(x,x);
    cout << x << endl;
}