class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int i=satisfaction.size()-1, sum = 0;
        for(; i>=0; i--) {
            if(sum + satisfaction[i] > 0) sum += satisfaction[i];
            else break;
        }
        i++;
        int time = 1, res = 0;
        while(i < satisfaction.size()) {
            res += time*satisfaction[i];
            i++;
            time++;
        }
        return res;
    }
};