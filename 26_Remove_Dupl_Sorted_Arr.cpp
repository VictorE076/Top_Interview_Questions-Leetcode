#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void PrintVector(vector<int>& nums)
    {
        const int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n\n";
    }
    int removeDuplicates(vector<int>& nums) 
    {
        int k = 1;
        const int sz = nums.size();
        for (int i = 1; i < sz; i++)
        {
            if (nums[i] != nums[i - 1])
                nums[k++] = nums[i];
        }
        for (int i = k; i < sz; i++)
        {
            nums[i] = -1000;
        }
        return k;
    }
};
int main()
{
    // Example 1:
    vector<int> nums1 = { 1, 1, 2 };
    Solution s1;
    cout << "k1: " << s1.removeDuplicates(nums1) << "\n\n";
    s1.PrintVector(nums1);
    // Example 2:
    vector<int> nums2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    Solution s2;
    cout << "k2: " << s2.removeDuplicates(nums2) << "\n\n";
    s2.PrintVector(nums2);
    return 0;
}
