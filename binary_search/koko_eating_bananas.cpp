class Solution {
public:
    //function to check if the middle value is valid
    bool valid(vector<int>& piles, int cap, int H) {
        int total = 0;
        for(int i=0; i<piles.size(); i++) {
            int x = piles[i]/cap;
            int y = piles[i]%cap;
            if(y) x++;
            total+=x;
        }
        return total<=H;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = (int)(pow(10,9)+1);
        while(l < r) {
            int mid = l + (r-l)/2;
            if (valid(piles, mid, h)) r = mid;
            else l = mid+1;
        }
        return r;
    }
};