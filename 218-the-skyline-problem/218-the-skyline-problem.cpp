class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
       vector<vector<int>> an;
        vector<pair<int,int>> ans;
        set<int> st;
        for( auto i : buildings ){
            ans.push_back({i[0],-i[2]});
            ans.push_back({i[1], i[2]});
        }
        sort(ans.begin(),ans.end());
       int ma = 0;
        
    multiset<int>pq;
    pq.insert(0);
       for(auto i : ans){
           int x = i.first;
           int h = i.second;
           if(h < 0){
              pq.insert(-h);
           }
           else{
              auto it = pq.find(h);
              pq.erase(it);
           }
           int to =  *pq.rbegin();
           cout<<to<<" ";
           if(ma != to ){
            an.push_back({x,to});
            ma = to;
           }
       } 
        return an;
    }
        
};