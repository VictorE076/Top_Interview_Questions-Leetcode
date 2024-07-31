#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {

    //
    void printPrefixVector(const vector<int>& prefix) {

        cout << "\nPrefix Vector: ";

        for (const int elem : prefix) 
        {
            cout << elem << " ";
        }
        cout << "\n";
    }
    //

    void buildPrefixArray(vector<int>& t, const string& pattern, const int m) {
        
        int j = 0;
        for (int i = 1; i < m; i++)
        {
            while (j >= 0)
            {
                if (pattern[j] == pattern[i])
                    break;
                
                j--;
                if (j >= 0)
                    j = t[j];
            }

            j++;
            t[i] = j;
        }
    }

public:
    int strStr(string haystack, string needle) 
    {
        const int n = haystack.size(); // length of TEXT
        const int m = needle.size(); // length of PATTERN

        if(n < m)
            return -1;

        vector<int> prefix(m, 0);

        buildPrefixArray(prefix, needle, m); // O(m)

        // printPrefixVector(prefix);

        /// String Matching Algorithm using the prefix array - O(n + m)
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j >= 0)
            {
                if (haystack[i] == needle[j])
                    break;

                j--;
                if (j >= 0)
                    j = prefix[j];
            }

            j++;
            if (j >= m)
                return (i - m + 1);
        }

        return -1;
    }

};

int main()
{
    // Time Complexity: O(n + m) - KMP String Matching Algorithm.
    // 
    // Example 1:
    Solution s1;
    int sol1 = s1.strStr("sadbutsad", "sad");
    cout << "Solution 1: " << sol1 << "\n\n"; // 0


    // Example 2:
    Solution s2;
    int sol2 = s2.strStr("leetcode", "leeto");
    cout << "Solution 2: " << sol2 << "\n\n"; // -1


    // Example 3:
    Solution s3;
    int sol3 = s3.strStr("abcacacabacacabacacacabcacacabacacabacacaccbac", "acacabacacabacacac");
    cout << "Solution 3: " << sol3 << "\n\n"; // 3


    // Example 4:
    Solution s4;
    int sol4 = s4.strStr("ababaabba", "ababaaba");
    cout << "Solution 4: " << sol4 << "\n\n"; // -1


    // Example 5:
    Solution s5;
    int sol5 = s5.strStr("a", "a");
    cout << "Solution 5: " << sol5 << "\n\n"; // 0


    return 0;
}