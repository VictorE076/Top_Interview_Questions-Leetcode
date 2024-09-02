#include <iostream>
#include <vector>

using namespace std;

class Solution {

    int minInt(const int a, const int b) {
        if (a < b)
            return a;
        return b;
    }

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        const int sz = nums.size();

        if (sz <= 0)
            return 0;

        int minSubArrayLen = sz + 1;
        int sum = nums[0];
        int i = 0, j = 0;
        
        while (i <= j && i < sz && j < sz) 
        {
            if (sum < target)
            {
                j++;

                if (j < sz)
                    sum += nums[j];
            }
            else
            {
                minSubArrayLen = minInt(minSubArrayLen, j - i + 1);
                sum -= nums[i];
                i++;   
            }
        }

        if (minSubArrayLen > sz)
            return 0;

        return minSubArrayLen;
    }
};

int main()
{
    // Time Complexity: O(n) - Sliding Window Technique.
    //
    // Example 1:
    vector<int> nums1 = { 2, 3, 1, 2, 4, 3 };
    Solution s1;
    cout << "Solution 1: ";
    cout << s1.minSubArrayLen(7, nums1) << "\n\n"; // 2


    // Example 2:
    vector<int> nums2 = { 1, 4, 4 };
    Solution s2;
    cout << "Solution 2: ";
    cout << s2.minSubArrayLen(4, nums2) << "\n\n"; // 1


    // Example 3:
    vector<int> nums3 = { 1, 1, 1, 1, 1, 1, 1, 1 };
    Solution s3;
    cout << "Solution 3: ";
    cout << s3.minSubArrayLen(11, nums3) << "\n\n"; // 0


    return 0;
}
