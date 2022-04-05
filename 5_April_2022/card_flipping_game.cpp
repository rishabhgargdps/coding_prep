class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int>cantPick;
        int minimum = INT_MAX;
        for(int i=0; i<fronts.size(); i++) {
            if(fronts[i] == backs[i]) {
                cantPick.insert(fronts[i]);
            }
        }
        for(int i=0; i<fronts.size(); i++) {
            if(cantPick.find(fronts[i]) == cantPick.end()) {
                minimum = min(minimum, fronts[i]);
            }
            if(cantPick.find(backs[i]) == cantPick.end()) {
                minimum = min(minimum, backs[i]);
            }
        }
        return minimum == INT_MAX ? 0 : minimum;
    }
};

// INCORRECT--
// class Solution {
// public:
//     int flipgame(vector<int>& fronts, vector<int>& backs) {
//         unordered_set<int>front;
//         int minimum = INT_MAX;
//         for(int num : fronts) front.insert(num);
//         for(int i=0; i<backs.size(); i++) {
//             if(front.find(backs[i]) == front.end()) minimum = min(minimum, fronts[i]);
//         }
//         return minimum == INT_MAX ? 0 : minimum;
//     }
// };