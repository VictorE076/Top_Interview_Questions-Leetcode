#include <iostream>
#include <vector>

using namespace std;

class Solution {

    int _maxInt(const int a, const int b) {
        return (a > b) ? a : b;
    }

public:
    int rob(vector<int>& nums) {

        const char sz = (char)(nums.size());

        if (sz < 1)
            return 0;

        int globalMax = nums[0];
        int localMax = 0;
        int prevSum = nums[0];

        for (char i = 1; i < sz; i++)
        {
            int currentSum = localMax + nums[i];
            globalMax = _maxInt(globalMax, currentSum);

            localMax = _maxInt(localMax, prevSum);
            prevSum = currentSum;
        }

        return globalMax;
    }

    //
    void printVector(const vector<int>& v) {
        
        cout << "Vector: ";
        for (const int elem : v)
        {
            cout << elem << " ";
        }
        cout << "\n\n";
    }
    //

};

int main()
{
    // Time Complexity: O(n) - Using Dynamic Programming to calculate the maximum sum (amount of money) that can be robbed (for no adjacent elements) at each step.
    // Extra Space Complexity: O(1) - using only simple variables, not data structures.
    // 
    // Example 1:
    vector<int> nums1 = { 1, 2, 3, 1 };
    Solution s1;
    s1.printVector(nums1);
    cout << "Solution 1: ";
    cout << s1.rob(nums1) << "\n\n\n"; // 4


    // Example 2:
    vector<int> nums2 = { 2, 7, 9, 3, 1 };
    Solution s2;
    s2.printVector(nums2);
    cout << "Solution 2: ";
    cout << s2.rob(nums2) << "\n\n\n"; // 12


    return 0;
}
