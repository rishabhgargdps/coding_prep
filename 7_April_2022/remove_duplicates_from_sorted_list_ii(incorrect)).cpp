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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL, *curr = head, *next = curr->next;
        while(next != NULL) {
            if(curr->val == next->val) {
                while(next != NULL && curr->val == next->val) {
                    next = next->next;
                }
                if(prev) {
                    prev->next = next;
                    curr = next;
                    if(next) next = next->next;
                }
                else {
                    head = next;
                    prev = next;
                    curr = next;
                    if(next) next = next->next;
                }
            }
            else {
                prev = curr;
                curr = curr->next;
                if(next) next = next->next;
            }
        }
        return head;
    }
};