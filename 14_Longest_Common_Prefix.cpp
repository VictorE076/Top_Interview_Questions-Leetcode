#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
    string sol_ = "";
    bool same_letter_(vector<string>& strs, const int k)
    {
        const int sz = strs.size();
        for (int i = 0; i < sz - 1; i++)
        {
            if (strs[i][k] != strs[i + 1][k])
                return false;
        }
        return true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        const int sz = strs.size();
        int min_str_len = 201;
        for (int i = 0; i < sz; i++)
        {
            const int sz_i = strs[i].length();
            if (sz_i < min_str_len)
                min_str_len = sz_i;
        }
        for (int k = 0; k < min_str_len; k++)
        {
            bool same_symbol = same_letter_(strs, k);
            if (!same_symbol)
                return sol_;
            sol_ += strs[0][k];
        }
        return sol_;
    }
};
int main()
{
    // Example 1:
    vector<string> strs1 = { "flower", "flow", "flight" };
    Solution s1;
    string ss1 = s1.longestCommonPrefix(strs1);
    if (ss1.empty())
        cout << "Empty string!\n\n";
    else
        cout << ss1 << "\n\n";
    // Example 2:
    vector<string> strs2 = { "dog", "racecar", "car" };
    Solution s2;
    string ss2 = s2.longestCommonPrefix(strs2);
    if (ss2.empty())
        cout << "Empty string!\n\n";
    else
        cout << ss2 << "\n\n";
    return 0;
}