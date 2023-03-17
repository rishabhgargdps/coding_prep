class Trie {
public:
    struct TrieNode {
        bool end = false;
        TrieNode* children[26] = {NULL};
    };
    TrieNode* head = new TrieNode();
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* temp = head;
        for(int i=0; i<word.length(); i++) {
            char c = word[i];
            if(temp->children[c-'a'] == NULL) temp->children[c-'a'] = new TrieNode();
            temp = temp->children[c-'a'];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        TrieNode* temp = head;
        for(char c: word) {
            if(temp->children[c-'a'] == NULL) return false;
            temp = temp->children[c-'a'];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = head;
        for(char c: prefix) {
            if(temp->children[c-'a'] == NULL) return false;
            temp = temp->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */