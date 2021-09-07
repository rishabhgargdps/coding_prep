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
    ListNode *backtrack(ListNode *l1, ListNode *l2, int count1, int count2, int &carry)
    {
        if (count1 == 0 && count2 == 0)
        {
            return NULL;
        }
        ListNode *curr_node = count1 >= count2 ? l1 : l2;

        if (count1 > count2)
        {
            curr_node->next = backtrack(l1->next, l2, count1 - 1, count2, carry);
        }
        else if (count1 < count2)
        {
            curr_node->next = backtrack(l1, l2->next, count1, count2 - 1, carry);
        }
        else
        {
            curr_node->next = backtrack(l1->next, l2->next, count1 - 1, count2 - 1, carry);
        }

        if (count1 == count2)
        {
            curr_node->val = l1->val + l2->val;
        }

        curr_node->val += carry;
        carry = curr_node->val / 10;
        curr_node->val = curr_node->val % 10;
        return curr_node;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head;
        int count1 = 0;
        int count2 = 0;
        ListNode *temp = l1;
        while (temp)
        {
            count1++;
            temp = temp->next;
        }
        temp = l2;
        while (temp)
        {
            count2++;
            temp = temp->next;
        }
        int carry = 0;
        head = backtrack(l1, l2, count1, count2, carry);
        if (carry == 1)
        {
            ListNode *temp = new ListNode(1);
            temp->next = head;
            head = temp;
        }

        return head;
    }
};