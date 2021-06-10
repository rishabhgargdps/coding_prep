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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* prev = new ListNode();
        ListNode* temp;
        ListNode* head = prev;
        int carry=0, sum=0;
        while(p1!=NULL && p2!=NULL) {
            sum = p1->val+p2->val+carry;
            if (sum>9) {
                sum%=10;
                carry=1;
            }
            else if (sum<=9) carry=0;
            temp = new ListNode(sum);
            p1 = p1->next;
            p2 = p2->next;
            prev->next = temp;
            prev = prev->next;
        }
        while(p1!=NULL) {
            sum = p1->val+carry;
            if (sum>9) {
                sum%=10;
                carry=1;
            }
            else if (sum<=9) carry=0;
            temp = new ListNode(sum);
            p1 = p1->next;
            prev->next = temp;
            prev = prev->next;
        }
        while(p2!=NULL) {
            sum = p2->val+carry;
            if (sum>9) {
                sum%=10;
                carry=1;
            }
            else if (sum<=9) carry=0;
            temp = new ListNode(sum);
            p2 = p2->next;
            prev->next = temp;
            prev = prev->next;
        }
        if(carry) {
            temp = new ListNode(1);
            prev->next = temp;
            prev = prev->next;
        } 
        return head->next;
    }
};