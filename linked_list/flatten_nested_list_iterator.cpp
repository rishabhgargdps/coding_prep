/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int index=0;
    vector<int>v;
    void addELE(vector<int>&v, vector<NestedInteger>&nestedList) {
        for(auto itr: nestedList) {
            if(itr.isInteger()) v.push_back(itr.getInteger());
            else addELE(v, itr.getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        addELE(v, nestedList);
    }
    
    int next() {
        return v[index++];
    }
    
    bool hasNext() {
        if(index==v.size()) return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */