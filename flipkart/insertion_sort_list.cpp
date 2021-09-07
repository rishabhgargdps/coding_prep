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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head;
        while (temp != NULL)
        {
            ListNode *next = temp->next;
            ListNode *start = head;
            ListNode *prev = head;
            while (start != next)
            {
                if (start->val > temp->val)
                {
                    temp->next = start;
                    if (start == head)
                    {
                        head = temp;
                    }
                    else
                    {
                        prev->next = temp;
                    }
                    while (start->next != temp)
                    {
                        start = start->next;
                    }
                    start->next = next;
                }
                prev = start;
                start = start->next;
            }
            temp = next;
        }
        return head;
    }
};