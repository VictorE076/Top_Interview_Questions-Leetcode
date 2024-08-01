#include <iostream>
#include <vector>

using namespace std;

class Solution {

    void swapInt(int& a, int& b) {
        const int temp = a;
        a = b;
        b = temp;
    }

public:
    int removeElement(vector<int>& nums, int val) {
        
        const int n = nums.size();
        if (!n)
            return 0;

        int count = 0;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            if (nums[r] == val) {
                count++;
                r--;
                continue;
            }

            if (nums[l] == val) {
                swapInt(nums[l], nums[r]);
            }

            l++;
        }

        r = n - 1;
        while (r >= 0 && nums[r] == val) {
            nums[r--] = -1;
        }

        return (n - count);
    }

    //
    void printArray(const vector<int>& v) {
        
        cout << "\nArray 1: ";
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
    // Time Complexity: O(n) - removing all occurrences of an element in-place (swapping values using 2 pointers).
    // Extra Space: O(1) - in-place algorithm
    // 
    // Example 1:
    Solution s1;
    vector<int> nums1 = { 3, 2, 2, 3 };
    cout << "Solution 1: ";
    const int r1 = s1.removeElement(nums1, 3); // 2
    cout << r1 << endl;
    s1.printArray(nums1); // [2, 2, _, _]


    // Example 2:
    Solution s2;
    vector<int> nums2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
    cout << "Solution 2: ";
    const int r2 = s2.removeElement(nums2, 2); // 5
    cout << r2 << endl;
    s2.printArray(nums2); // [0, 1, 4, 0, 3, _, _, _]

    return 0;
}
