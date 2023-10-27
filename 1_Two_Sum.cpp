#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    int get_index(vector<int>& nums, const int k, const int val)
    {
        int sz = nums.size();
        for (int i = 0; i < k && i < sz; i++)
        {
            if (nums[i] == val)
                return i;
        }
        return k;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_set<int> u_s;
        int sz = nums.size();
        u_s.insert(nums[0]);
        for (int i = 1; i < sz; i++)
        {
            if (u_s.find(target - nums[i]) != u_s.end())
            {
                int first_index = get_index(nums, i, target - nums[i]);
                return { first_index, i };
            }
            u_s.insert(nums[i]);
        }
        return { -1, -1 };
    }
};
int main()
{
    // Example 1:
    vector<int> nums1 = { 2, 7, 11, 15 };
    int target1 = 9;
    Solution s1;
    vector<int> sol1 = s1.twoSum(nums1, target1);
    cout << sol1[0] << " " << sol1[1] << endl << endl;
    // Example 2:
    vector<int> nums2 = { 3, 2, 4 };
    int target2 = 6;
    Solution s2;
    vector<int> sol2 = s2.twoSum(nums2, target2);
    cout << sol2[0] << " " << sol2[1] << endl << endl;
    // Example 3:
    vector<int> nums3 = { 3, 3 };
    int target3 = 6;
    Solution s3;
    vector<int> sol3 = s3.twoSum(nums3, target3);
    cout << sol3[0] << " " << sol3[1] << endl << endl;
    return 0;
    ///
    // Time Complexity: O(n);
    ///
}
