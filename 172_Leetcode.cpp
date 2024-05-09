#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        
        int numZeroes = 0;
        int pow5 = 5;

        while (pow5 <= n) {
            numZeroes += (int)(n / pow5);
            pow5 *= 5;
        }

        return numZeroes;
    }
};

int main()
{
    // Time Complexity: O(log(n)) - Powers of 5.
    //
    // Example 1:
    int n1 = 3;
    Solution s1;
    cout << "Solution 1: " << s1.trailingZeroes(n1) << "\n\n"; // 0


    // Example 2:
    int n2 = 5;
    Solution s2;
    cout << "Solution 2: " << s2.trailingZeroes(n2) << "\n\n"; // 1


    // Example 3:
    int n3 = 0;
    Solution s3;
    cout << "Solution 3: " << s3.trailingZeroes(n3) << "\n\n"; // 0


    return 0;
}
