#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if (!left)
            return 0;

        if (left == right)
            return left;

        int pow2 = 1, solBitwiseAND = 0;

        while (left > 0 || right > 0) {
            
            int leftBit = left % 2;
            int rightBit = right % 2;

            if (leftBit != rightBit) 
                solBitwiseAND = 0;
            else
                solBitwiseAND += leftBit * pow2;

            pow2 = pow2 << 1;

            left = left >> 1;
            right = right >> 1;
        }

        return solBitwiseAND;
    }
};

int main()
{
    // Time Complexity: O(log(n)) - Binary Representations (Longest Common Binary Prefix).
    // 
    // Example 1:
    Solution s1;
    cout << s1.rangeBitwiseAnd(5, 7) << "\n\n"; // 4


    // Example 2:
    Solution s2;
    cout << s2.rangeBitwiseAnd(0, 0) << "\n\n"; // 0


    // Example 3:
    Solution s3;
    cout << s3.rangeBitwiseAnd(1, 2147483647) << "\n\n"; // 0


    return 0;
}
