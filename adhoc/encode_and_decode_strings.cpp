#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string encode(vector<string>&strs) { //conversion of the vector into string
    string str="";
    for (string s: strs) {
        str+=to_string(s.length());
        str+='#';
        str+=s;
    }
    return str;
}

vector<string>decode(string &s) {
    vector<string>res;
    int n = s.size();
    int i=0;
    while (i<n) {
        string temp="";
        int j;
        for(j=i;s[j]!='#';j++) {
            temp+=s[j];
        }
        j++;
        string str = s.substr(j,stoi(temp));
        res.push_back(str);
        i = j+stoi(temp);
    }
    return res;
}

int main() {
    vector<string>v={"abc","24%2"};
    string a = encode(v);
    v = decode(a);
    return 0;
}