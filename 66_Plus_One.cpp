#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void PrintVector(vector<int>& v)
    {
        const int sz = v.size();
        for (int i = 0; i < sz; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n\n";
    }
    vector<int> plusOne(vector<int>& digits) 
    {
        const int sz = digits.size();
        int rest = 0;
        if (digits[sz - 1] + 1 > 9)
            rest = 1;
        digits[sz - 1] = (digits[sz - 1] + 1) % 10;
        for (int i = sz - 2; i >= 0; i--)
        {
            if (digits[i] + rest > 9)
            {
                digits[i] = (digits[i] + rest) % 10;
                rest = 1;
            }
            else
            {
                digits[i] = digits[i] + rest;
                rest = 0;
            }
        }
        if(!rest)
            return digits;
        digits.push_back(digits[sz - 1]);
        for (int i = sz - 1; i > 0; i--)
        {
            digits[i] = digits[i - 1];
        }
        digits[0] = 1;
        return digits;
    }
};
int main()
{
    // Example 1:
    vector<int> digits1 = { 1, 2, 3 };
    Solution s1;
    digits1 = s1.plusOne(digits1);
    s1.PrintVector(digits1);
    // Example 2:
    vector<int> digits2 = { 4, 3, 2, 1 };
    Solution s2;
    digits2 = s2.plusOne(digits2);
    s2.PrintVector(digits2);
    // Example 3:
    vector<int> digits3 = { 9 };
    Solution s3;
    digits3 = s3.plusOne(digits3);
    s3.PrintVector(digits3);
    return 0;
}
