class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return false;
        unordered_set<int>d;
        for(int i=0; i<s.length(); i++) {
            int diff = t[i] - s[i];
            int temp = diff;
            if(diff < 0) {
                temp = abs(diff);
                int q = temp / 26;
                int r = temp % 26;
                temp = q * 26 + 26 - r;
            }
            while(d.find(temp) != d.end() && temp < k) {
                auto itr = d.find(temp);
                temp = *itr + 26;
                cout << temp << endl;
            }
            if(temp > k) return false;
            if(temp != 0) d.insert(temp);
        }
        return true;
    }
};