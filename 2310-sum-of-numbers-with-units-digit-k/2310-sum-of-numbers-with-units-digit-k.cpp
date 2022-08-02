class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0) return 0;
        int unit = num%10;
        unordered_map<int, int>m;
        for(int i=1; i<=10; i++) {
            int x = (k*i)%10;
            if(m.find(x) == m.end()) m[x] = i;
        }
        if(m.find(unit) == m.end()) return -1;
        cout << m[unit];
        if(num < m[unit]*k) return -1;
        return m[unit];
    }
};