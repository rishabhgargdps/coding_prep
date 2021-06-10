#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* first;
    bool stop = false;
    void reverse(ListNode* last, int left, int right) {
        if (right == 1) return;
        last = last->next;
        if (left > 1) {
            first = first->next;
        }
        reverse(last, left-1, right-1);
        if (first == last || last->next == first) stop = true;
        if (!stop) {
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
            first = first->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        first = head;
        reverse(head, left, right);
        return head;
    }
};