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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* oddhead = head;
        ListNode* evenhead = head->next;
        ListNode* temp = evenhead;
        while(evenhead && evenhead->next) {
            oddhead->next = oddhead->next->next;
            evenhead->next = evenhead->next->next;
            oddhead = oddhead->next;
            evenhead = evenhead->next;
        }
        oddhead->next = temp;
        return head;
    }
};