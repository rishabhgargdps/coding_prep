// class Solution {
// public:
//     int calculate(string s) {
//         stack<string>stk;
//         //string processing
//         std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
//         s.erase(end_pos, s.end());
//         string temp="";
//         string temp2, temp3, temp4;
//         int res=0;
//         if (s[0]=='+') s.erase(s.begin());
//         for(int i=0; i<s.length()-1;i++) {
//             temp = s.substr(i,2);
//             if(temp=="++") {
//                 s.erase(s.begin()+i+1);
//                 i--;
//             }
//             else if(temp=="+-") {
//                 s[i]='-';
//                 s.erase(s.begin()+i+1);
//                 i--;
//             }
//             else if(temp=="-+") {
//                 s.erase(s.begin()+i+1);
//                 i--;
//             }
//             else if(temp=="--") {
//                 s[i]='+';
//                 s.erase(s.begin()+i+1);
//                 i--;
//             }
//             else if(temp=="(+" || temp=="(-") {
//                 s.erase(s.begin()+i+1);
//             }
//         }
//         temp="";
//         //calculation for elements within brackets and storing inside the stack
//         for(int i=0; i<s.length(); i++) {
//             if(s[i]=='(' || s[i]=='+' || s[i]=='-') {
//                 temp+=s[i];
//                 stk.push(temp);
//                 // cout << temp << endl;
//                 temp="";
//             }
//             else if(s[i]==')') {
//                 //evaluate the expression till we encounter a '('
//                 while(stk.top()!="(") {
//                     res=0;
//                     temp2 = stk.top();
//                     stk.pop();
//                     // cout << temp2 << endl;
//                     temp3 = stk.top();
//                     if(temp3=="(") break;
//                     stk.pop();
//                     // cout << temp3 << endl;
//                     temp4 = stk.top();
//                     stk.pop();
//                     // cout << temp4 << endl;
//                     if(temp3=="+") {
//                         res+=(stoi(temp2)+stoi(temp4));
//                     }
//                     else if(temp3=="-") {
//                         res+=(stoi(temp4)-stoi(temp2));
//                     }
//                     // cout << res << endl;
//                     string res2 = to_string(res);
//                     stk.push(res2);
//                 }
//                 stk.pop();
//                 stk.push(temp2);
//             }
//             else {
//                 while(s[i]>='0' && s[i]<='9' && i<s.length()) {
//                     temp+=s[i];
//                     i++;
//                 }
//                 i--;
//                 stk.push(temp);
//                 // cout << temp << endl;
//                 temp="";
//             }
//         }
//         //calculation for elements remaining in the stack;
//         while(stk.size()!=1) {
//             temp2 = stk.top();
//             stk.pop();
//             // cout << temp2;
//             temp3 = stk.top();
//             stk.pop();
//             // cout << temp3;
//             temp4 = stk.top();
//             stk.pop();
//             // cout << temp4;
//             if(temp3=="+") {
//                 res = stoi(temp2)+stoi(temp4);
//             }
//             else if(temp=="-") {
//                 res = stoi(temp4) - stoi(temp3);
//             }
//             stk.push(to_string(res));
//         }
//         return stoi(stk.top());
//     }
// };

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int>pq;
        int sum = 0;
        int sign = 1;
        for(int i = 0;i<n;i++)
        {
           
           if(isdigit(s[i]))
           {
                int val = 0;
                while(i<n and isdigit(s[i]))
                {
                    val = val*10 + (s[i]-'0');
                    i++;
                }
               i--;
               val= val*sign;
               sum+=val;
               sign = 1;
           }
            else if(s[i] == '(')
            {
                pq.push(sum);
                pq.push(sign);
                sign = 1;
                sum = 0;
            }
            else if(s[i] == ')')
            {
                sum*= pq.top();
                pq.pop();
                sum += pq.top();
                pq.pop();
            }
            else if(s[i] == '-')
                sign*=-1;
        }
        return sum;
    }
};