#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* slow = head;
        if (!head)
            return false;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};