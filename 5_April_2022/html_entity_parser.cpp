class Solution {
public:
    string entityParser(string text) {
        int i=0;
        string res = "";
        while(i < text.length()) {
            if(text[i] == '&') {
                if(text.substr(i, 6) == "&quot;") {
                    res += "\"";
                    i += 6;
                }
                else if(text.substr(i, 6) == "&apos;") {
                    res += "'";
                    i += 6;
                }
                else if(text.substr(i, 5) == "&amp;") {
                    res += "&";
                    i += 5;
                }
                else if(text.substr(i, 4) == "&gt;") {
                    res += ">";
                    i += 4;
                }
                else if(text.substr(i, 4) == "&lt;") {
                    res += "<";
                    i += 4;
                }
                else if(text.substr(i, 7) == "&frasl;") {
                    res += "/";
                    i += 7;
                }
                else {
                    res += "&";
                    i++;
                }
            }
            else {
                res += text[i];
                i++;
            }
        }
        return res;
    }
};