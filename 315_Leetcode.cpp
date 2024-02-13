#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution 
{

public:

    //
    void PrintVector(vector<int>& v)
    {
        cout << "Vector:\t";
        for (const int elem : v)
        {
            cout << elem << " ";
        }
        cout << endl << endl;
    }
    //

    void Merge(vector<int>& nums, vector<int>& ind, vector<int>& counts, const int l, const int r, const int m)
    {
        vector<int> larray(m - l + 1);
        vector<int> rarray(r - m);

        int c = 0;
        for (int a = l; a <= m; a++)
        {
            larray[c++] = ind[a];
        }
        c = 0;
        for (int a = m + 1; a <= r; a++)
        {
            rarray[c++] = ind[a];
        }

        int i = 0, j = 0;
        c = l;

        while (i < m - l + 1 && j < r - m)
        {
            if (nums[larray[i]] <= nums[rarray[j]])
            {
                counts[larray[i]] += j;
                ind[c++] = larray[i++];
            }
            else
            {
                ind[c++] = rarray[j++];
            }
        }

        while (i < m - l + 1)
        {
            counts[larray[i]] += j;
            ind[c++] = larray[i++];
        }

        while (j < r - m)
        {
            ind[c++] = rarray[j++];
        }
    }

    void MergeSort(vector<int>& nums, vector<int>& ind, vector<int>& counts, const int l, const int r)
    {
        int m = l + ((r - l) >> 1);

        if (l < r)
        {
            MergeSort(nums, ind, counts, l, m);
            MergeSort(nums, ind, counts, m + 1, r);

            Merge(nums, ind, counts, l, r, m);
        }
    }

    vector<int> countSmaller(vector<int>& nums) 
    {
        const int n = nums.size();

        vector<int> ind(n);
        vector<int> counts(n, 0);

        for (int i = 0; i < n; i++)
        {
            ind[i] = i;
        }

        //
        // PrintVector(ind);
        // PrintVector(counts);
        //

        MergeSort(nums, ind, counts, 0, n - 1);

        return counts;
    }
};

int main()
{
    // Time Complexity: O(n * log(n)) - Solution with AVL (Index) Trees with "node count for each left subtree in the path for the new inserted node" for each inserted element. 
    // Time Complexity: O(n * log(n)) - Solution with "MergeSort" in Ascending Order (!!! This is a stable sorting algorithm).
    // 
    // Example 1:
    cout << "Solution 1:\n";
    vector<int> nums1 = { 5, 2, 6, 1 };
    Solution s1;
    nums1 = s1.countSmaller(nums1);
    s1.PrintVector(nums1); // [2, 1, 1, 0]

    // Example 2:
    cout << "Solution 2:\n";
    vector<int> nums2 = { -1 };
    Solution s2;
    nums2 = s2.countSmaller(nums2);
    s2.PrintVector(nums2); // [0]

    // Example 3:
    cout << "Solution 3:\n";
    vector<int> nums3 = { -1, -1 };
    Solution s3;
    nums3 = s3.countSmaller(nums3);
    s3.PrintVector(nums3); // [0, 0]

    // Example 4:
    cout << "Solution 4:\n";
    vector<int> nums4 = { 2, 0, 1 };
    Solution s4;
    nums4 = s4.countSmaller(nums4);
    s4.PrintVector(nums4); // [2, 0, 0]

    // Example 5:
    cout << "Solution 5:\n";
    vector<int> nums5 = { 6, 2, 1, 5, 3, 1, 4 };
    Solution s5;
    nums5 = s5.countSmaller(nums5);
    s5.PrintVector(nums5); // [6, 2, 0, 3, 1, 0, 0]

    return 0;
}


