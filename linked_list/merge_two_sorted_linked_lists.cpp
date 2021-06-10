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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* res = NULL;
        if (p1==NULL) return p2;
        else if (p2==NULL) return p1;
        else if (p1->val < p2->val) {
            res = l1;
            p1 = p1->next;
        }
        else {
            res = l2;
            p2 = p2->next;
        }
        ListNode* head = res;
        while(p1!=NULL && p2!=NULL) {
            if (p1->val < p2->val) {
                res->next = p1;
                res = res->next;
                p1 = p1->next;
            }
            else {
                res->next = p2;
                res = res->next;
                p2 = p2->next;
            }
        }
        
        if(p1==NULL) res->next = p2;
        else res->next = p1;
        return head;
    }
};