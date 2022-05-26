class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int res = 0;
        int temp = capacity;
        for(int i=0; i<plants.size(); i++) {
            if(temp >= plants[i]) {
                temp -= plants[i];
                res++;
            }
            else {
                temp = capacity - plants[i];
                res += 2*i+1;
            }
        }
        return res;
    }
};