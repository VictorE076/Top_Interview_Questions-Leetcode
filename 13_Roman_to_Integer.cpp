#include <iostream>
#include <string>
using namespace std;
class Solution {
    const int limit = (int)('X' - 'A' + 1);
    const char chr_(const int i)
    {
        return (char)('A' + i);
    }
    const int ord_codes_(const char a)
    {
        return (int)(a - 'A');
    }
    void codes_roman_(int* codes)
    {
        for (int i = 0; i < this->limit; i++)
        {
            char c = chr_(i);
            switch (c)
            {
            case 'I':
                codes[i] = 1;
                break;
            case 'V':
                codes[i] = 5;
                break;
            case 'X':
                codes[i] = 10;
                break;
            case 'L':
                codes[i] = 50;
                break;
            case 'C':
                codes[i] = 100;
                break;
            case 'D':
                codes[i] = 500;
                break;
            case 'M':
                codes[i] = 1000;
                break;
            default:
                codes[i] = 0;
                break;
            }
        }
    }
public:
    int romanToInt(string s) 
    {
        const int sz = s.length();
        int* codes;
        codes = new int[this->limit];
        codes_roman_(codes);
        int ct = 0;
        int sol_int = 0;
        while (ct < sz - 1)
        {
            const int first = ord_codes_(s[ct]);
            const int second = ord_codes_(s[ct + 1]);
            if (codes[first] >= codes[second])
            {
                sol_int += codes[first];
                ct++;
            }
            else
            {
                const int temp_int = codes[second] - codes[first];
                sol_int += temp_int;
                ct += 2;
            }
        }
        if (ct == sz - 1)
        {
            const int cd = ord_codes_(s[ct]);
            sol_int += codes[cd];
        }
        delete[] codes;
        return sol_int;
    }
};
int main()
{
    // Example 1:
    string a1 = "III";
    Solution s1;
    cout << s1.romanToInt(a1) << "\n\n"; // 3
    // Example 2:
    string a2 = "LVIII";
    Solution s2;
    cout << s2.romanToInt(a2) << "\n\n"; // 58
    // Example 3:
    string a3 = "MCMXCIV";
    Solution s3;
    cout << s3.romanToInt(a3) << "\n\n"; // 1994
    return 0;
}

