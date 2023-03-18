class BrowserHistory {
public:
    struct ListNode {
        string val = "";
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode() {}
        ListNode(string val) {this->val = val;}
    };
    ListNode* head;
    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
    }
    
    void visit(string url) {
        ListNode* curr = new ListNode(url);
        head->next = curr;
        curr->prev = head;
        head = head->next;
    }
    
    string back(int steps) {
        while(head->prev != NULL && steps > 0) {
            steps--;
            head = head->prev;
        }
        return head->val;
    }
    
    string forward(int steps) {
        while(head->next != NULL && steps > 0) {
            steps--;
            head = head->next;
        }
        return head->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */