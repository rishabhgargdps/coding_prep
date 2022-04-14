class Solution {
public:
    unordered_map<int,bool>map;
    bool dfs(int msi,int total,vector<bool>&nums,int sum,int mask)
    {
        if(map.find(mask)!=map.end())//if already encountered before use it
        {
            if(map[mask]==true)return false;
            else return true;
        }
        
        bool ans=true;
        for(int i=1;i<=msi;i++)
        {
            if((mask&(1<<(i-1)))==0)//if the i-1 th bit is unset
            {
                if(sum +i>=total)return true;
                mask=(mask|(1<<(i-1)));//setting the i-1 th bit(0 based indexing while number starts from 1)
                ans=ans and dfs(msi,total,nums,sum+i,mask);
                mask=(mask&(~(1<<(i-1))));//unsetting the i-1th bit
            }
        }
        map[mask]=ans;
        if(!ans)return true;
        else return false;
    }
    
    bool canIWin(int msi, int total) {
        int mask=0;
        vector<bool>nums(msi+1,false);
        if(msi*(msi+1)/2<total)return false;//sum is unreachable
        return dfs(msi,total,nums,0,mask);
        
    }
};