#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>>res;
        for (vector<int>restaurant : restaurants) {
            if(veganFriendly) {
                if (restaurant[2] && restaurant[3]<=maxPrice && restaurant[4]<=maxDistance) {
                    res.push_back(restaurant);
                }
            }
            else {
                if (restaurant[3]<=maxPrice && restaurant[4]<=maxDistance) res.push_back(restaurant);
            }
        }
        sort(res.begin(),res.end(),[](vector<int>&v1, vector<int>&v2){
            if(v1[1]!=v2[1]) return v1[1]>v2[1];
            return v1[0]>v2[0];
        });
        vector<int>final_res;
        for(vector<int>restaurant : res) {
            final_res.push_back(restaurant[0]);
        }
        return final_res;
    }
};