#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> sol;

        for (int i = 0; i < numRows; i++)
        {
            sol.push_back({ 1 });
            if (i == 0)
                continue;
            
            const int nr = sol[i - 1].size();
            for (int j = 1; j < nr; j++)
            {
                int val = sol[i - 1][j - 1] + sol[i - 1][j];
                sol[i].push_back(val);
            }
            sol[i].push_back(1);
        }

        return sol;
    }

    void Print_PascalTriangle(vector<vector<int>>& v)
    {
        for (const vector<int>& v_i : v)
        {
            for (const int elem : v_i)
            {
                cout << elem << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }

};

int main()
{
    // Time Complexity: O(n^2) - "x" number of elements for row number "x"
    //
    // Example 1:
    int numRows1 = 5;
    Solution s1;
    vector<vector<int>> v1 = s1.generate(numRows1);
    cout << "Solution 1:\n";
    s1.Print_PascalTriangle(v1); // [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

    // Example 2:
    int numRows2 = 1;
    Solution s2;
    vector<vector<int>> v2 = s2.generate(numRows2);
    cout << "Solution 2:\n";
    s2.Print_PascalTriangle(v2); // [[1]]

    return 0;
}