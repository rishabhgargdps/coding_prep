class LRUCache
{
public:
    struct Node
    {
        int key;
        int val;
        Node *next;
        Node *prev;
    };

    Node *head = new Node();
    Node *tail = new Node();
    unordered_map<int, Node *> node_map;
    int cache_capacity;

    LRUCache(int capacity)
    {
        this->cache_capacity = capacity;
        node_map = unordered_map<int, Node *>(cache_capacity);
        head->next = tail;
        tail->next = head;
    }

    int get(int key)
    {
        int res = -1;
        Node *node = node_map[key];
        if (node != NULL)
        {
            res = node->val;
            remove(node);
            add(node);
        }
        return res;
    }

    void put(int key, int value)
    {
        Node *node = node_map[key];
        if (node != NULL)
        {
            remove(node);
            node->val = value;
            add(node);
        }
        else
        {
            if (node_map.size() == cache_capacity)
            {
                node_map.erase(tail->prev->key);
                remove(tail->prev);
            }
            Node *new_node = new Node();
            new_node->key = key;
            new_node->val = value;
            node_map.insert({key, new_node});
            add(new_node);
        }
    }

    void add(Node *node)
    {
        Node *head_next = head->next;
        node->next = head_next;
        head_next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void remove(Node *node)
    {
        Node *next_node = node->next;
        Node *prev_node = node->prev;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache
{
public:
    int sz = 0;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> dq;
    LRUCache(int capacity)
    {
        sz = capacity;
    }

    int get(int key)
    {

        if (mp.find(key) == mp.end())
            return -1;

        int value = (*mp[key]).first;
        dq.erase(mp[key]);
        dq.push_front({value, key});
        mp[key] = dq.begin();
        return dq.front().first;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end()) // not in cache
        {
            if (dq.size() >= sz) //if  cache is full
            {
                int last = dq.back().second;
                mp.erase(last);
                dq.pop_back();
            }

            dq.push_front({value, key});
            mp[key] = dq.begin();
        }
        else //present in cache
        {
            dq.erase(mp[key]);           //removed old value from cache
            dq.push_front({value, key}); // push new value to cache
            mp[key] = dq.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */