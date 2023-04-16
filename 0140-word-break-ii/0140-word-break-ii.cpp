class Solution {
public:
    vector<vector<string>>res;
    void solve(unordered_set<string>& dict, string &s, int curr_index, vector<string>curr) {
        if(curr_index == s.length()) {
            res.push_back(curr);
            return;
        }
        for(int i=curr_index; i<s.length(); i++) {
            string temp = s.substr(curr_index, i-curr_index+1);
            if(dict.find(temp) != dict.end()) {
                curr.push_back(temp);
                solve(dict, s, i+1, curr);
                curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict;
        for(auto &word: wordDict) {
            dict.insert(word);
        }
        solve(dict, s, 0, {});
        vector<string>ans;
        for(auto &v: res) {
            string temp = "";
            for(auto &str: v) {
                temp+= str + " ";
            }
            temp = temp.substr(0, temp.length()-1);
            ans.push_back(temp);
        }
        return ans;
    }
};