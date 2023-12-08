#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ruleCompare(const int a, const int b)
{
    return (a < b);
}

class Solution 
{
    vector<vector<int>> sol;

    void PrintVector_(vector<int>& v)
    {
        for (const int elem : v)
        {
            cout << elem << " ";
        }
        cout << endl << endl;
    }

    bool skip_duplicates_(vector<int>& v, const int index)
    {
        if (this->sol.empty())
            return false;

        const int sz_sol = this->sol.size();

        if (this->sol[sz_sol - 1][0] != v[index])
            return false;
        
        return true;
    }

    bool add_sol_(vector<int>& v, const int l, const int r)
    {
        if (this->sol.empty())
            return true;

        const int sz_sol = this->sol.size();

        if (!(this->sol[sz_sol - 1][1] == v[l] && this->sol[sz_sol - 1][2] == v[r]))
            return true;

        return false;
    }

    void TwoPointers_(vector<int>& v, const int left, const int right, const int target)
    {
        int l = left, r = right;
        while (l < r)
        {
            if (v[l] + v[r] == target)
            {
                bool check_solution = add_sol_(v, l, r); // O(1)
                if(check_solution)
                    this->sol.push_back({ v[left - 1], v[l], v[r] });
                
                l++;
            }
            else if (v[l] + v[r] < target)
                l++;
            else
                r--;
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), ruleCompare); // O(n*log(n))
        
        // PrintVector_(nums);

        const int sz = nums.size();
        for (int c = 0; c < sz - 2; c++)
        {
           if (skip_duplicates_(nums, c)) // O(1)
                continue;

            TwoPointers_(nums, c + 1, sz - 1, (-1) * nums[c]); // O(n)
        }

        return this->sol;
    }

    void PrintSolution()
    {
        for (const vector<int>& triplet : this->sol)
        {
            cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
        }
        cout << endl;
    }
};

int main()
{
    // Time Complexity: O(n^2) - Sort the array and apply "2 pointers" solution for each element in the array.
    // 
    // Example 1:
    Solution s1;
    vector<int> nums1 = { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> v1 = s1.threeSum(nums1);
    cout << "Solution 1:\n";
    s1.PrintSolution(); // [[-1, -1, 2], [-1, 0, 1]]

    // Example 2:
    Solution s2;
    vector<int> nums2 = { 0, 1, 1 };
    vector<vector<int>> v2 = s2.threeSum(nums2);
    cout << "Solution 2:\n";
    s2.PrintSolution(); // []

    // Example 3:
    Solution s3;
    vector<int> nums3 = { 0, 0, 0 };
    vector<vector<int>> v3 = s3.threeSum(nums3);
    cout << "Solution 3:\n";
    s3.PrintSolution(); // [0, 0, 0]

    return 0;
}
