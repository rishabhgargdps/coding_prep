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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp2 = head;
        ListNode* temp3 = head;
        if(head==NULL || head->next==NULL || left==right) return head;
        while(--left-1) {
            temp2 = temp2->next;
        }
        ListNode* temp1 = temp2;
        temp2 = temp2->next;
        while(--right) {
            temp3 = temp3->next;
        }
        ListNode* temp4 = temp3->next;
        ListNode* prev = temp2;
        ListNode* curr = temp2->next;
        ListNode* next = temp2->next->next;
        do {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = (next!=NULL)?next->next:NULL;
        } while(curr!=temp4);
        temp1->next = temp3;
        temp2->next = temp4;
        return head;
    }
};