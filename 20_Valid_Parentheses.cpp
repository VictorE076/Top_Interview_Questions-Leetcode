#include <iostream>
#include <stack>
using namespace std;
class Solution {
    bool same_bracket_(string& s, stack<char>& st, const int index)
    {
        if (st.empty())
            return false;
        if (s[index] == ')' && st.top() == '(')
            return true;
        if (s[index] == ']' && st.top() == '[')
            return true;
        if (s[index] == '}' && st.top() == '{')
            return true;
        return false;
    }
public:
    bool isValid(string s) 
    {
        stack<char> st;
        const int sz = s.length();
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                bool s_b = same_bracket_(s, st, i);
                if (!s_b)
                    return false;
                st.pop();
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
int main()
{
    // Example 1:
    string st1 = "()";
    Solution s1;
    cout << s1.isValid(st1) << "\n\n"; // TRUE
    // Example 2:
    string st2 = "()[]{}";
    Solution s2;
    cout << s2.isValid(st2) << "\n\n"; // TRUE
    // Example 3:
    string st3 = "(]";
    Solution s3;
    cout << s3.isValid(st3) << "\n\n"; // FALSE
    return 0;
}