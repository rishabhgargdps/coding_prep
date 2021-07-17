class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int, int> m;
    RandomizedSet()
    {
        v.clear();
        unordered_map<int, int> m1;
        swap(m, m1);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m.find(val) == m.end())
        {
            v.push_back(val);
            m[val] = v.size() - 1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (m.find(val) != m.end())
        {
            int index = m[val];
            v[index] = v[v.size() - 1];
            m[v[v.size() - 1]] = index;
            v.pop_back();
            m.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int index = rand() % v.size();
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */