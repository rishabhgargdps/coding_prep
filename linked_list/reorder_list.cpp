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
    void reorderList(ListNode *head)
    {
        ListNode *temp = head;
        if (head == NULL || head->next == NULL)
            return;
        vector<int> res;
        while (temp != NULL)
        {
            res.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i = 0;
        int j = res.size() - 1;
        while (temp != NULL)
        {
            temp->val = res[i];
            i++;
            temp = temp->next;
            if (temp != NULL)
            {
                temp->val = res[j];
                j--;
                temp = temp->next;
            }
        }
    }
};

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
    void reorderList(ListNode *head)
    {
        ListNode *temp = head;
        stack<ListNode *> stk;
        int count = 0;
        while (temp != NULL)
        {
            stk.push(temp);
            temp = temp->next;
        }
        count = stk.size();
        if (count <= 2)
            return;
        temp = head;
        ListNode *next;
        for (int i = 0; i < count / 2; i++)
        {
            next = temp->next;
            temp->next = stk.top();
            stk.pop();
            temp = temp->next;
            temp->next = next;
            temp = temp->next;
        }
        temp->next = NULL;
    }
};

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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == NULL || head->next == NULL)
            return;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL;
        ListNode *curr = slow;
        ListNode *next = slow->next;
        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if(next!=NULL) next = next->next;
        }
        slow = head;
        fast = prev;
        ListNode* temp;
        //merging of two lists
        while (fast->next != NULL)
        {
            temp = slow->next;
            slow->next = fast;
            slow = temp;
            temp = fast->next;
            fast->next = slow;
            fast = temp;
        }
    }
};