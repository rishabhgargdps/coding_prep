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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *curr = temp;
        while (curr->next != NULL && curr->next->next != NULL)
        {
            ListNode *first_node = curr->next;
            ListNode *second_node = curr->next->next;
            first_node->next = second_node->next;
            second_node->next = first_node;
            curr->next = second_node; //very important
            curr = second_node->next;
        }
        return temp->next;
    }
};