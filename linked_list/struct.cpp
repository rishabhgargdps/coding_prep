#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* ptr;
    Node() : val(0), ptr(nullptr) {}
    Node(int val, Node*ptr) : val(val), ptr(ptr) {}
    Node(int val) : val(val) {}
};

int main() {
    Node* head = new Node(0);
    return 0;
}