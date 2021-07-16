class Trie
{
private:
    struct TrieNode
    {
        TrieNode *child[26];
        bool isEnd = false;
        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
        }
    };

public:
    /** Initialize your data structure here. */
    TrieNode *root = new TrieNode();
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string key)
    {
        TrieNode *curr = root;
        for (int i = 0; i < key.length(); i++)
        {
            if (curr->child[key[i] - 'a'] == NULL)
            {
                curr->child[key[i] - 'a'] = new TrieNode();
            }
            curr = curr->child[key[i] - 'a'];
        }
        curr->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string key)
    {
        TrieNode *curr = root;
        for (int i = 0; i < key.length(); i++)
        {
            if (curr->child[key[i] - 'a'] == NULL)
                return false;
            curr = curr->child[key[i] - 'a'];
        }
        return curr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (curr->child[prefix[i] - 'a'] == NULL)
                return false;
            curr = curr->child[prefix[i] - 'a'];
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