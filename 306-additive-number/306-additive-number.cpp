class Solution {
public:
    string sum(string s1, string s2) {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        string res; int c=0; int i=0;
        for(; i<min(s1.length(),s2.length()); i++) {
            int n=(s1[i]-'0'+s2[i]-'0')+c;
            res+=to_string(n%10);
            c=n/10;
        }
        for(; i<s1.length(); i++) {
            int n=(s1[i]-'0')+c;
            res+=to_string(n%10);
            c=n/10;
        }
        for(; i<s2.length(); i++) {
            int n=(s2[i]-'0')+c;
            res+=to_string(n%10);
            c=n/10;
        }
        while(c!=0){
            res+=to_string(c%10);
            c=c/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    bool check(string a, string b, string s) {
        //Base case
        if(s == "") return true;
        //Recursive step
        string n = sum(a, b);
        if(n == s.substr(0, n.length()) && check(b, n, s.substr(n.length()))) return true;
        return false;
    }
    bool isAdditiveNumber(string num) {
        string a, b;
        for(int i=1; i<num.length(); i++) {
            for(int j=i+1; j<num.length(); j++) {
                a = num.substr(0, i);
                b = num.substr(i, j-i);
                if(b[0]=='0' && b.length()>1) continue;
                string s= num.substr(j);
                if(check(a, b, s)) return true;
            }
        }
        return false;
    }
};