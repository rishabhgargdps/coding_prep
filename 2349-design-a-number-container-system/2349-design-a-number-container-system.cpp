class NumberContainers {
public:
    unordered_map<int, int>i_n;
    unordered_map<int, set<int>>n_i;
    NumberContainers() {
        i_n.clear();
        n_i.clear();
    }
    
    void change(int index, int number) {
        int prev_num = i_n[index];
        i_n[index] = number;
        n_i[prev_num].erase(index);
        n_i[number].insert(index);
    }
    
    int find(int number) {
        if(n_i[number].size() == 0) return -1;
        return *n_i[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */