#include <iostream>
#include <vector>

using namespace std;

class Solution {

    /* 
    
        Bitwise Operators:

            ^   XOR
            &   AND
            |   OR
            ~   NOT (Complement)

    */

public:
    int singleNumber(vector<int>& nums) {
        
        const int sz = nums.size();

        int ones = 0, twos = 0;

        for (int i = 0; i < sz; i++)
        {
            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }

        return ones;
    }
};

int main()
{
    // Time Complexity: O(n) - Bitwise Operations.
    // Constant (O(1)) Extra Space.
    //
    // Example 1:
    vector<int> nums1 = { 2, 2, 3, 2 };
    Solution s1;
    cout << "Solution 1: " << s1.singleNumber(nums1) << "\n\n"; // 3


    // Example 2:
    vector<int> nums2 = { 0, 1, 0, 1, 0, 1, 99 };
    Solution s2;
    cout << "Solution 2: " << s2.singleNumber(nums2) << "\n\n"; // 99

    return 0;
}
