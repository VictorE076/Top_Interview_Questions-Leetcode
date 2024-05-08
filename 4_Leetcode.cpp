#include <iostream>
#include <vector>

using namespace std;

class Solution {

    double avgVal(const int a, const int b) {
        return (double)((double)(a) / 2 + (double)(b) / 2);
    }

    int minVal(const int a, const int b) {
        if (a < b)
            return a;
        return b;
    }

    int maxVal(const int a, const int b) {
        if (a > b)
            return a;
        return b;
    }

    double MedianSortedArrays(vector<int>& v, vector<int>& a) {
        const int m = v.size(), n = a.size();
        const int total = m + n;
        const int half = total >> 1;

        if (!total)
            return DBL_MAX;

        if (!n)
            return (total % 2 != 0) ? (double)(v[half]) : (double)(avgVal(v[half - 1], v[half]));

        int l = -1, r = n; // Including "Edge Cases"
        while (l <= r) {
            const int pos_a = l + ((r - l) >> 1);
            const int pos_v = (half - 1) - (pos_a + 1);

            /// cout << pos_v << " " << pos_a << endl;

            const int maxLeft_v = (pos_v < 0) ? INT_MIN : v[pos_v];
            const int maxLeft_a = (pos_a < 0) ? INT_MIN : a[pos_a];
            const int minRight_v = (pos_v >= m - 1) ? INT_MAX : v[pos_v + 1];
            const int minRight_a = (pos_a >= n - 1) ? INT_MAX : a[pos_a + 1];

            if (maxLeft_v <= minRight_a && minRight_v >= maxLeft_a)
                return (total % 2 != 0) ? (double)(minVal(minRight_v, minRight_a)) : (double)(avgVal(maxVal(maxLeft_v, maxLeft_a), minVal(minRight_v, minRight_a)));
            else if (maxLeft_v > minRight_a)
                l = pos_a + 1;
            else
                r = pos_a - 1;
        }
        
        return DBL_MAX;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();

        if (m > n)
            return MedianSortedArrays(nums1, nums2);
        
        return MedianSortedArrays(nums2, nums1);
    }
};

int main()
{
    // Time Complexity: O(log(min(m, n))) - "Binary Search" on Smaller Size Array.
    //
    // Example 1:
    vector<int> nums1_1 = { 1, 3 };
    vector<int> nums2_1 = { 2 };
    Solution s1;
    cout << "Solution 1: " << s1.findMedianSortedArrays(nums1_1, nums2_1) << "\n\n"; // 2.00000


    // Example 2:
    vector<int> nums1_2 = { 1, 2 };
    vector<int> nums2_2 = { 3, 4 };
    Solution s2;
    cout << "Solution 2: " << s2.findMedianSortedArrays(nums1_2, nums2_2) << "\n\n"; // 2.50000


    return 0;
}