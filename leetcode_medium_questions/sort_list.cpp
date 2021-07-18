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
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        ListNode *sorted_list = new ListNode(0);
        ListNode *curr_node = sorted_list;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val <= temp2->val)
            {
                curr_node->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                curr_node->next = temp2;
                temp2 = temp2->next;
            }
            curr_node = curr_node->next;
        }
        while (temp1 != NULL)
        {
            curr_node->next = temp1;
            temp1 = temp1->next;
            curr_node = curr_node->next;
        }
        while (temp2 != NULL)
        {
            curr_node->next = temp2;
            temp2 = temp2->next;
            curr_node = curr_node->next;
        }
        return sorted_list->next;
    }

    ListNode *sortList(ListNode *head)
    {
        //Base case
        if (head == NULL || head->next == NULL)
            return head;
        //Recursive step
        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode *left_side = sortList(head);
        ListNode *right_side = sortList(slow);
        return merge(left_side, right_side);
    }
};