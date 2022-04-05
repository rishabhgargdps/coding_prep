class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string>res;
        unordered_map<string, int>m;
        for(string domain : cpdomains) {
            string val = "";
            int index = 0;
            for(; index<domain.length(); index++) {
                if(domain[index] == ' ') break;
                val += domain[index];
            }
            string d = "";
            for(int i = domain.length()-1; i >=0 ; i--) {
                if(domain[i] == '.') {
                    string temp = d;
                    reverse(temp.begin(), temp.end());
                    m[temp] += stoi(val);
                }
                if(domain[i] == ' ') break;
                d += domain[i];
            }
            string temp = d;
            reverse(temp.begin(), temp.end());
            m[temp] += stoi(val);
        }
        for(auto itr = m.begin(); itr != m.end(); ++itr) {
            string temp = to_string(itr->second) + " " + itr->first;
            res.push_back(temp);
        }
        return res;
    }
};