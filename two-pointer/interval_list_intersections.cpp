class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>res;
        vector<vector<int>>::iterator i= firstList.begin(); 
        vector<vector<int>>::iterator j = secondList.begin();
        while(i!=firstList.end() && j!=secondList.end()) {
            if((*i)[1] < (*j)[1]) {
                int first_point = ((*i)[0]<(*j)[0])?(*j)[0]:(*i)[0];
                int second_point = (*i)[1];
                if(first_point<=second_point) res.push_back({first_point, second_point});
                i++;
            }
            else {
                int first_point = ((*i)[0]<(*j)[0])?(*j)[0]:(*i)[0];
                int second_point = (*j)[1];
                if(first_point<=second_point) res.push_back({first_point, second_point});
                j++;
            }
        }
        return res;
    }
};