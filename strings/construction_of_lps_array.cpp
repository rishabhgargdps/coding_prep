#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> lps(string s)
{
    vector<int> res(s.length(), 0);
    int i = 1, j = 0;
    while (i < res.size()) {
        if (s[i] == s[j]) {
            res[i++] = ++j;
        } else {
            if (j == 0)
                res[i] = 0;
            else {
                while (j > 0) {
                    --j;
                    if (s[i] == s[res[j]]) {
                        res[i] = ++res[j];
                        j = res[j];
                        j++;
                        res[i] = j;
                        break;
                    } else
                        j = res[j];
                }
            }
        }
    }
}

int main()
{
    string s = "abcdab";
    vector<int> v = lps(s);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    return 0;
}