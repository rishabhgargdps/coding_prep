class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() {
            this->val = 0;
            this->next = NULL;
        }
        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
    };
    
    ListNode* head;
    ListNode* tail;
    int size = 0;
    
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        ListNode* temp = head;
        while(index) {
            temp = temp->next;
            index--;
        }
        ListNode*temp2 = head;
        while(temp2 != NULL) {
            cout << temp2->val << endl;
            temp2 = temp2->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* temp = new ListNode(val);
        temp->next = head;
        head = temp;
        size++;
        if(size == 1) tail = head;
    }
    
    void addAtTail(int val) {
        ListNode* temp = new ListNode(val);
        tail->next = temp;
        tail = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        if(index < 0 || index > size) return;
        ListNode* temp = head; 
        int count = 0;
        while (count < index-1) {
            temp = temp->next; 
            count++;
        }
        
        ListNode* next = temp->next; 
        ListNode* node = new ListNode(val);
        temp->next = node; 
        node->next = next; 
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > size) return;
        ListNode* temp = head;
        bool update = false; 
        if (head == tail) {
            update = true; 
        }
        
        int count = 0; 
        ListNode* cursor = head;
        
        while (count < index-1) {
            cursor = cursor->next; 
            count++;
        }
        
        if (index == 0) {
            head = head->next; 
            if (update) tail = head;
        }
        else if (index == size-1 ) {
            tail = cursor; 
            if (update) head = tail;
        }
        else {
            ListNode* next = cursor->next->next; 
            cursor->next = next; 
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */