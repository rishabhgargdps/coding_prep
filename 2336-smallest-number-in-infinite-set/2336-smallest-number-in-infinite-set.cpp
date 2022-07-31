class SmallestInfiniteSet {
public:
    vector<int>v;
    int i;
    SmallestInfiniteSet() {
        v.resize(1000, 1);
        i=0;
    }
    
    int popSmallest() {
        for(int i=0; i<1000; i++) {
            if(v[i] == 1) {
                v[i] = 0;
                return i+1;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        v[num-1]=1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */