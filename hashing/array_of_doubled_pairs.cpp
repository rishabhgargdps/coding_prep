class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int &x, int &y){
            return abs(x) < abs(y);
        });
        unordered_map<int,int>m;
        for(int x: arr) {
            m[x]++;
        }
        for(int i=0; i<arr.size(); i++) {
            if(m[arr[i]] == 0) {
                continue;
            }
            if(m.find(arr[i]*2)==m.end() || m[arr[i]*2]==0) {
                return false;
            }
            m[arr[i]*2]--;
            m[arr[i]]--;
        }
        return true;
    }
};