class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        vector<string>str;
        for (int i:nums) str.push_back(to_string(i));
        sort(str.begin(), str.end(), [](string a, string b){
            return a+b > b+a;
        });
        for (string a: str) res+=a;
        while (res[0]=='0') {
            res.erase(0,1);
        }
        if (res=="") return "0";
        return res;
    }
};