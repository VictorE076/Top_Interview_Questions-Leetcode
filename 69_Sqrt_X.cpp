#include <iostream>
using namespace std;
class Solution {
    int binary_search_x_(const int x, const int left, const int right)
    {
        if (left >= right)
            return left;
        unsigned long long m = left + ((right - left) >> 1);
        if (m * m <= x && x < (m + 1) * (m + 1))
            return m;
        if (m * m > x)
            return binary_search_x_(x, left, m);
        return binary_search_x_(x, m, right);
    }
public:
    int mySqrt(int x) 
    {
        if (x == 0 || x == 1)
            return x;
        int left = 1;
        int right = (x >> 1) + 1;
        int square_root = binary_search_x_(x, left, right);
        return square_root;
    }
};
int main()
{
    // Example 1:
    int x1 = 4;
    Solution s1;
    cout << x1 << " " << s1.mySqrt(x1) << "\n\n";
    // Example 2:
    int x2 = 8;
    Solution s2;
    cout << x2 << " " << s2.mySqrt(x2) << "\n\n";
    return 0;
}

