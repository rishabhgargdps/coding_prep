

//INCORRECT--
// class Solution {
// public:
//     bool identifyOpenTag(string code, string &open_tag_name, int i) {
//         //open tag
//         bool flag = false;
//         if(code[i] == '<' && code.substr(i, 1) != "/" && code.substr(i, 1) != "!") {
//             flag = true;
//             open_tag_name = "";
//             i++;
//             while(i < code.length() && code[i] != '>') {
//                 open_tag_name += code[i];
//                 i++;
//             }
//         }
//         return flag;
//     }
//     bool identifyCloseTag(string code, string &close_tag_name, int i) {
//         //close tag
//         bool flag = false;
//         if(code.substr(i, 2) == "</") {
//             flag = true;
//             close_tag_name = "";
//             i+=2;
//             while(i < code.length() && code[i] != '>') {
//                 close_tag_name += code[i];
//                 i++;
//             }
//         }
//         return flag;
//     }
//     bool identifyOpenCdata(string code, int i) {
//         if(code.substr(i, 9) == "<![CDATA[") return true;
//         return false;
//     }
//     bool identifyCloseCdata(string code, int i) {
//         if(code.substr(i, 2) == "]]") return true;
//         return false;
//     }
//     bool validTagName(string name) {
//         if(name.length() == 0 || name.length() > 9) return false;
//         for(int i=0; i<name.length(); i++) {
//             if('A' > name[i] || name[i] > 'Z') return false;
//         }
//         return true;
//     }
//     bool isValid(string code) {
//         int i=0;
//         string open_tag_name;
//         string close_tag_name;
//         while(i < code.length()) {
//             if(identifyOpenTag(code, open_tag_name, i) && !validTagName(open_tag_name)) return false;
//             i++;
//             //tag content
//             stack<string>stk;
//             while(i < code.length()) {
//                 if(identifyOpenTag(code, open_tag_name, i)){
//                     if(!validTagName(open_tag_name)) return false;
//                     stk.push("<");
//                 }
//                 else if(identifyCloseTag(code, close_tag_name, i)) {
//                     if(stk.empty()) break;
//                     if(stk.top() != "<") return false;
//                     if(!validTagName(close_tag_name)) return false;
//                     if(open_tag_name != close_tag_name) return false;
//                     stk.pop();
//                 }
//                 else if(identifyOpenCdata(code, i)) {
//                     stk.push("!");
//                 }
//                 else if(identifyCloseCdata(code, i)) {
//                     if(stk.empty() || stk.top() != "!") return false;
//                     stk.pop();
//                 }
//                 i++;
//             }
//             //closing tag
//             if(!validTagName(close_tag_name)) return false;
//             if(open_tag_name != close_tag_name) return false;
//             i++;
//         }
//         return true;
//     }
// };