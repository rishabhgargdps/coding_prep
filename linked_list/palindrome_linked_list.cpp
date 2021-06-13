#include <iostream>
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* next = slow->next;
        while(next!=NULL) {
            prev=curr;
            curr=next;
            next=next->next;
            curr->next=prev;
        }
        ListNode* newHead = curr;
        slow->next=NULL;
        ListNode *c1=head,*c2=newHead;
        while(c2){
            if(c1->val!=c2->val){
                return false;
            }
            c1=c1->next;
            c2=c2->next;
        }
        return true;
    }
};