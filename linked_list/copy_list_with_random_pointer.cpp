/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>m;
        Node* temp = head;
        while(temp!=NULL) {
            Node* new_node = new Node(temp->val);
            m[temp] = new_node;
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL) {
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        Node* newHead = m[head];
        return newHead;
    }
};