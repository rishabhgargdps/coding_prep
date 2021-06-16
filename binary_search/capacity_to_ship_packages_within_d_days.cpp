class Solution {
public:
    bool valid(const vector<int>& weights, int cap, int D) {
        int days = 1;
        int total = 0;
        for(int i=0; i<weights.size(); i++) {
            if(weights[i]>cap) return false;
            if(total+weights[i]<=cap) {
                total+=weights[i];
            }
            else {
                days++;
                total = weights[i];
            }
        }
        return days<=D;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;
        int r = 500*5*pow(10,4);
        while(l<r) {
            int mid = l + (r-l)/2;
            if(valid(weights, mid, days)) {
                r = mid;
            }
            else l = mid+1;
        }
        return r;
    }
};