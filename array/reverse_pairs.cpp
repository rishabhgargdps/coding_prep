class Solution {
public:
    typedef long long int ll;
    ll count=0ll;
    void merge(vector<int>&v, int l, int mid, int r) {
        vector<ll>temp_l(v.begin()+l,v.begin()+mid+1);
        vector<ll>temp_r(v.begin()+mid+1,v.begin()+r+1);
        int i=0,j=0,k=l,temp2=0;
        while(i < temp_l.size() && temp2 < temp_r.size()){
            if(temp_l[i] > (ll)2*temp_r[temp2]){
                count+=(temp_l.size()-i);
                temp2++;
            } 
            else {
                i++;
            }
        }
        i=0;
        j=0;
        while(i<temp_l.size() && j<temp_r.size()) {
            if (temp_l[i]<=temp_r[j]) v[k++] = temp_l[i++];
            else v[k++] = temp_r[j++];
        }
        while(i<temp_l.size()) {
            v[k++] = temp_l[i++];
        }
        while(j<temp_r.size()) {
            v[k++] = temp_r[j++];
        }
    }

    void mergeSort(vector<int>&v, int l, int r) {
        if (l<r) {
            int mid = l + (r-l)/2;
            mergeSort(v,l,mid);
            mergeSort(v,mid+1,r);
            merge(v,l,mid,r);
        }
        return;
    }

    void print(const vector<int>&v) {
        for (int i: v) {
            cout << i << " ";
        }
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        print(nums);
        return count;
    }
};