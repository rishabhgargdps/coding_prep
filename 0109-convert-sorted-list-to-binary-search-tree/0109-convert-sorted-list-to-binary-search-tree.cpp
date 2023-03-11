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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(ListNode* left, ListNode* right) {
        if(left == NULL || right->next == left) return NULL;
        if(left == right) return new TreeNode(left->val);
        ListNode* slow = left;
        ListNode* fast = left;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* head = new TreeNode(slow->val);
        ListNode* prev = left;
        while(prev && prev->next != slow) {
            prev = prev->next;
        }
        prev->next = NULL;
        head->left = solve(left, prev);
        ListNode* next = slow->next;
        slow->next = NULL;
        head->right = solve(next, right);
        return head;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* curr = head;
        ListNode* tail = head;
        while(curr != NULL) {
            tail = curr;
            curr = curr->next;
        }
        return solve(head, tail);
    }
};