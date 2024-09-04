#include <iostream>
#include <vector>

using namespace std;

class Solution {

    short minShortInt(const short a, const short b) {
        if (a < b)
            return a;
        return b;
    }

    short maxShortInt(const short a, const short b) {
        if (a > b)
            return a;
        return b;
    }

    void printVector(const vector<short>& v) {

        cout << "Vector: ";
        for (const short elem : v)
        {
            cout << elem << " ";
        }
        cout << "\n\n";
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        const short m = matrix.size();
        const short n = m > 0 ? matrix[0].size() : 0;

        vector<short> cCons(n, 0);
        vector<short> areas(n, 0);

        short maximalSquare = 0;
        short rCons = 0;
        short lastSquareVal = 0;

        for (short i = 0; i < m; i++)
        {
            rCons = 0;
            for (short j = 0; j < n; j++)
            {
                /// 1. -> Calculating the consecutive number of '1's for each value (row / column). 
                rCons = (matrix[i][j] == '1') ? (rCons + 1) : 0;
                cCons[j] = (matrix[i][j] == '1') ? (cCons[j] + 1) : 0;

                /// 2. -> Calculating largest square area containing only '1's at each step, given the already visited matrix values.
                if (!(i && j)) {
                    lastSquareVal = areas[j];
                    areas[j] = (short)(matrix[i][j] - '0');
                }
                else {
                    const short minConsMargin = minShortInt(rCons, cCons[j]);
                    const short newArea = minShortInt(minConsMargin, lastSquareVal + 1);
                    lastSquareVal = areas[j];
                    areas[j] = newArea;
                }
              
                maximalSquare = maxShortInt(maximalSquare, areas[j]);
            }
        }

        return (int)(maximalSquare * maximalSquare);
    }

    void printBinMatrix(const vector<vector<char>>& matrix) {

        for (const vector<char>& line : matrix)
        {
            for (const char elem : line)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    // Time Complexity: O(m * n) - Using Dynamic Programming to find the largest square area in the matrix, containing only '1's.
    // Extra Space: O(n) - Store the last row at each line, updating 2 arrays dynamically.
    // 
    // Example 1:
    vector<vector<char>> matrix1 = { {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'} };
    Solution s1;
    cout << "Solution 1:\n";
    s1.printBinMatrix(matrix1);
    cout << "Sol. 1, Area: " << s1.maximalSquare(matrix1) << "\n\n\n"; // 4


    // Example 2:
    vector<vector<char>> matrix2 = { {'0', '1'}, {'1', '0'} };
    Solution s2;
    cout << "Solution 2:\n";
    s2.printBinMatrix(matrix2);
    cout << "Sol. 2, Area: " << s2.maximalSquare(matrix2) << "\n\n\n"; // 1


    // Example 3:
    vector<vector<char>> matrix3 = { {'0'} };
    Solution s3;
    cout << "Solution 3:\n";
    s3.printBinMatrix(matrix3);
    cout << "Sol. 3, Area: " << s3.maximalSquare(matrix3) << "\n\n\n"; // 0


    return 0;
}
