#include <iostream>
#include <climits>
#include <limits>
using namespace std;

const int MAX_LIMIT = INT_MAX;
const int MIN_LIMIT = INT_MIN;

class Solution 
{
    int abs_(const int x)
    {
        if (x == MIN_LIMIT)
            return 0;
        if (x < 0)
            return (-1) * x;
        return x;
    }
public:
    int reverse(int x) 
    {
        int inv = 0;
        int cpy = abs_(x);

        while (cpy > 0)
        {
            if ((double)(inv) > (double)((MAX_LIMIT - (cpy % 10)) / 10))
                return 0;

            inv = inv * 10 + cpy % 10;
            cpy /= 10;
        }

        if (x < 0)
            inv = (-1) * inv;
        return inv;
    }
};

int main()
{
    // Time Complexity: O(log(x)) - Number of digits of "x".
    //
    // Example 1:
    Solution s1;
    cout << "Solution 1:\n";
    cout << s1.reverse(123) << endl << endl; // 321

    // Example 2:
    Solution s2;
    cout << "Solution 2:\n";
    cout << s2.reverse(-123) << endl << endl; // -321

    // Example 3:
    Solution s3;
    cout << "Solution 3:\n";
    cout << s3.reverse(120) << endl << endl; // 21

    return 0;
}
