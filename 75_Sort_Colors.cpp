#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    void my_swap_(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int sort_eachColor_(vector<int>& nums, const int color, const int begin)
    {
        const int sz = nums.size();
        int pos = begin;
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] != color)
                continue;

            my_swap_(nums[i], nums[pos]);
            pos++;
        }

        return pos;
    }

public:
    void sortColors(vector<int>& nums) 
    {
        int lastPos = 0;

        for (int c = 0; c < 3; c++)
        {
            lastPos = sort_eachColor_(nums, c, lastPos); // O(n)
        }
    }

    void PrintArray(vector<int>& arr)
    {
        for (const int elem : arr)
        {
            cout << elem << " ";
        }
        cout << endl << endl;
    }
};

int main()
{
    // Time Complexity: O(n) -- Swap in-place in array 3 times (3 colors: red, white and blue) in total
    // Auxiliary Space: O(1) -- Constant
    //
    // Example 1:
    vector<int> nums1 = { 2, 0, 2, 1, 1, 0 };
    Solution s1;
    s1.sortColors(nums1);
    s1.PrintArray(nums1); // [0, 0, 1, 1, 2, 2]

    // Example 2:
    vector<int> nums2 = { 2, 0, 1 };
    Solution s2;
    s2.sortColors(nums2);
    s2.PrintArray(nums2); // [0, 1, 2]

    return 0;
}