#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if (matrix.empty())
            return;

        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<bool> rows(m, false);
        vector<bool> columns(n, false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = true;
                    columns[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (!rows[i])
                continue;

            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!columns[i])
                continue;

            for (int j = 0; j < m; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }

    void PrintMatrix(vector<vector<int>>& matrix)
    {
        for (const vector<int>& row : matrix)
        {
            for (const int elem : row)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
};

int main()
{
    // Time Complexity: O(m * n) -- Size of the input matrix.
    // Auxiliary Space: O(m + n) -- 2 boolean arrays of size "m" and "n" respectively. ""
    //
    // Example 1:
    vector<vector<int>> m1 = { {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
    Solution s1;
    s1.setZeroes(m1);
    s1.PrintMatrix(m1); // [[1, 0, 1], [0, 0, 0], [1, 0, 1]]
    
    // Example 2:
    vector<vector<int>> m2 = { {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5} };
    Solution s2;
    s2.setZeroes(m2);
    s2.PrintMatrix(m2); // [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]

    return 0;
}