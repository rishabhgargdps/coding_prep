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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m, vector<int>(n, -1));
        int top=0, bottom=m-1, left=0, right=n-1;
        bool stop=false;
        while(head != NULL) {
            for(int i=left; i<=right; i++) {
                res[top][i] = head->val;
                head = head->next;
                if(head == NULL) {
                    stop=true;
                    break;
                }
            }
            if(stop == true) break;
            top++;
            for(int i=top; i<=bottom; i++) {
                res[i][right] = head->val;
                head = head->next;
                if(head == NULL) {
                    stop=true;
                    break;
                }
            }
            if(stop == true) break;
            right--;
            for(int i=right; i>=left; i--) {
                res[bottom][i] = head->val;
                head = head->next;
                if(head == NULL) {
                    stop=true;
                    break;
                }
            }
            if(stop == true) break;
            bottom--;
            for(int i=bottom; i>= top; i--) {
                res[i][left] = head->val;
                head = head->next;
                if(head == NULL) {
                    stop=true;
                    break;
                }
            }
            left++;
        }
        return res;
    }
};