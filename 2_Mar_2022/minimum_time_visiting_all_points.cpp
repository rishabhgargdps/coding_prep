class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        if(points.size() == 0 || points.size() == 1) return 0;
        int res = 0;
        vector<int>initial_point = points[0];
        vector<int>curr_point = {0,0};
        for(int i=1; i<points.size(); i++) {
            int temp_1 = 0;
            curr_point = points[i];
            //equalize x-coordinate
            int dist_x = abs(curr_point[0] - initial_point[0]); 
            temp_1 = dist_x;
            //equalize the old/new y-coordinate
            int dist_y = abs(curr_point[1] - initial_point[1]);
            temp_1 += min(dist_y, abs(dist_y - dist_x));
            
            int temp_2 = 0;
            
            //equalize y-coordinate
            temp_2 = dist_y;
            //equalize the old/new x-coordinate
            temp_2 += min(dist_x, abs(dist_x - dist_y));
            
            res += min(temp_1, temp_2);
            
            initial_point = curr_point;
        }
        return res;
    }
};