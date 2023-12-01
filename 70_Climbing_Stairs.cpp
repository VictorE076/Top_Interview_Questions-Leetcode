#include <iostream>
#include <vector>
#include <climits>
#include <limits>
using namespace std;

class Solution 
{
public:
    int climbStairs(int n) 
    {
        if (n < 3)
            return n;

        int a = 1;
        int b = 2;
        int current = -1;
        for (int i = 3; i <= n; i++)
        {
            current = a + b;
            if (i == n)
                return current;

            a = b;
            b = current;
        }

        return current;
    }
};

int main()
{
    // Time Complexity: O(n)
    // Space complexity: O(1)

    // Example 1:
    int n1 = 2;
    Solution s1;
    cout << n1 << "  sol 1: " << s1.climbStairs(n1) << endl;

    // Example 2:
    int n2 = 3;
    Solution s2;
    cout << n2 << "  sol 2: " << s2.climbStairs(n2) << endl;
    return 0;
}
