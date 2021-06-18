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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        stack<int>stk;
        vector<int>v;
        while(temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        vector<int>res(v.size(), -1);
        temp = head;
        for(int i=0; i<v.size(); i++) {
            while(!stk.empty() && v[stk.top()] < v[i]) {
                res[stk.top()] = v[i];
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            res[stk.top()] = 0;
            stk.pop();
        }
        return res;
    }
};