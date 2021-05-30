class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size(), m = votes[0].size();
        vector<vector<int>>rank(26,vector<int>(26,0));
        string temp = votes[0];
        sort(temp.begin(), temp.end());
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                rank[votes[i][j]-temp[0]][j]++;
            }
        }
        sort(votes[0].begin(), votes[0].end(),[rank,m,temp](char &a, char &b){
            int i=0;
            while (rank[a-temp[0]][i]==rank[b-temp[0]][i]) {
                i++;
                if(i==m)return a<b;
            }
            return rank[a-temp[0]][i] > rank[b-temp[0]][i];
        });
        return votes[0];
    }
};