class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> stk;
        stk.push("");
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stk.push("");
            }
            else if (s[i] == ')')
            {
                string temp = stk.top();
                reverse(temp.begin(), temp.end());
                stk.pop();
                stk.top() += temp;
            }
            else
            {
                stk.top() += s[i];
            }
        }
        return stk.top();
    }
};