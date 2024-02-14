#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;

class Solution 
{
    int minim(const int a, const int b)
    {
        if (a < b)
            return a;
        return b;
    }

public:

    int lengthOfLongestSubstring(string s) 
    {
        int maxLength = 0;
        int localLength = 0;

        unordered_map<char, int> um;

        // cout << endl << endl;

        int i = 0;
        for (const char c : s)
        {
            if (um.find(c) == um.end()) // Char NOT Found
            {
                localLength = minim(i + 1, localLength + 1);
            }
            else // Char Found
            {
                localLength = minim(i - um[c], localLength + 1);
            }

            // cout << localLength << " ";

            um[c] = i;
            if (localLength > maxLength)
                maxLength = localLength;

            i++;
        }

        // cout << endl << endl;

        return maxLength;
    }
};

int main()
{
    // Time Complexity: O(n) - Using "unordered_map" operations (O(1) in average) for each character.
    //
    // Example 1:
    string s1 = "abcabcbb";
    Solution ss1;
    cout << "Solution 1:\t" << ss1.lengthOfLongestSubstring(s1) << "\n\n"; // 3

    // Example 2:
    string s2 = "bbbbb";
    Solution ss2;
    cout << "Solution 2:\t" << ss2.lengthOfLongestSubstring(s2) << "\n\n"; // 1

    // Example 3:
    string s3 = "pwwkew";
    Solution ss3;
    cout << "Solution 3:\t" << ss3.lengthOfLongestSubstring(s3) << "\n\n"; // 3

    return 0;
}
