class Solution {
public:
    bool digit(string word) {
        return find_if(word.begin(), word.end(), ::isdigit) != word.end();     
    }
    int hyphen(string word) {
        int flag = 0; //does not contain
        for(int i=0; i<word.length(); i++) {
            if(word[i] == '-') {
                if(flag == 0) {
                    if(i == 0) return -1; //contains and is not ok
                    if(i == word.length() - 1) return -1;
                    char x1 = word[i-1], x2 = word[i+1];
                    if(x1 < 'a' || x1 > 'z') return -1;
                    if(x2 < 'a' || x2 > 'z') return -1;
                    flag = 1; //contains and is ok
                }
                else return -1;
            }
        }
        return flag;
    }
    bool ispunct(char c) {
        if(c == '!' || c == '.' || c == ',') return true;
        return false;
    }
    int punc(string word) {
        for(int i=0; i<word.length(); i++) {
            if(ispunct(word[i]) && i!=word.length()-1) return -1;
        }
        return 0;
    }
    int countValidWords(string sentence) {
        int res = 0;
        istringstream ss(sentence);
        string word;
        while(ss >> word) {
            if(!digit(word) && hyphen(word) != -1 && punc(word) != -1) {
                res++;
            }
        }
        return res;
    }
};