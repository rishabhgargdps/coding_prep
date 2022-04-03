class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        for(int i=0; i<endTime.size(); i++) {
            if(startTime[i] <= queryTime && queryTime <= endTime[i]) {
                res++;
            }
        }
        return res;
    }
};