#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
    void copyVectors_(vector<int>& merged, vector<int>& nums1)
    {
        const int sz_merged = merged.size();
        for (int i = 0; i < sz_merged; i++)
        {
            nums1[i] = merged[i];
        }
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> merged(m + n);
        
        int i = 0, j = 0, count = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                merged[count++] = nums1[i++];
            else
                merged[count++] = nums2[j++]; 
        }

        while (i < m)
        {
            merged[count++] = nums1[i++];
        }

        while (j < n)
        {
            merged[count++] = nums2[j++];
        }

        copyVectors_(merged, nums1);
    }

    void printVector(vector<int>& nums1)
    {
        for (const int val : nums1)
        {
            cout << val << " ";
        }
        cout << endl << endl;
    }
};
int main()
{
    // Time Complexity: O(n + m);
    // Space Complexity: O(n + m);

    // Example 1:
    vector<int> a1 = { 1, 2, 3, 0, 0, 0 };
    int m1 = 3;
    vector<int> b1 = { 2, 5, 6 };
    int n1 = 3;
    Solution s1;
    s1.merge(a1, m1, b1, n1);
    s1.printVector(a1); // [1, 2, 2, 3, 5, 6]

    // Example 2:
    vector<int> a2 = { 1 };
    int m2 = 1;
    vector<int> b2 = { };
    int n2 = 0;
    Solution s2;
    s2.merge(a2, m2, b2, n2);
    s2.printVector(a2); // [1]

    // Example 3:
    vector<int> a3 = { 0 };
    int m3 = 0;
    vector<int> b3 = { 1 };
    int n3 = 1;
    Solution s3;
    s3.merge(a3, m3, b3, n3);
    s3.printVector(a3); // [1]
    return 0;
}