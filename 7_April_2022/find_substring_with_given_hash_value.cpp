class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int curr_sum = 0;
        for(int i=0; i<k; i++) {
            curr_sum += (s[i]-'a'+1)*pow(power, i);
        }
        for(int i=0; i+k<s.length(); i++) {
            if(curr_sum % modulo == hashValue) return s.substr(i, k);
            else {
                curr_sum -= (s[i]-'a'+1)*pow(power, i);
                curr_sum += (s[i+k]-'a'+1)*pow(power, i+k);
            }
        }
        return "";
    }
};