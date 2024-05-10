#include <iostream>
#include <vector>

using namespace std;

class Solution {

    const int Xaxis[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    const int Yaxis[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    bool isValidPos(const int i, const int j, const int m, const int n) {
        if (0 <= i && i < m && 0 <= j && j < n)
            return true;
        return false;
    }

public:

    void PrintBoard(vector<vector<int>>& board) {
        for (const vector<int>& row : board) {
            for (const int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    void gameOfLife(vector<vector<int>>& board) {
        
        const int m = board.size();
        const int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int countOnes = 0;
                for (int k = 0; k < 8; k++)
                {
                    const int ni = i + Xaxis[k];
                    const int nj = j + Yaxis[k];

                    if (!isValidPos(ni, nj, m, n))
                        continue;

                    countOnes += board[ni][nj] % 10;
                }

                int updated = board[i][j];

                if (!board[i][j] && countOnes == 3)
                        updated = 1;
                else if (board[i][j] && (countOnes < 2 || countOnes > 3))
                        updated = 0;
                
                board[i][j] = updated * 10 + board[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = board[i][j] / 10;
            }
        }
    }
};

int main()
{
    // Time Complexity: O(m * n) - Matrix (Each cell interacts with its 8 neighbors).
    //
    // Example 1:
    vector<vector<int>> board1 = { {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0} };
    Solution s1;
    s1.gameOfLife(board1);
    cout << "Solution 1:\n";
    s1.PrintBoard(board1); // [[0, 0, 0], [1, 0, 1], [0, 1, 1], [0, 1, 0]]

    
    // Example 2:
    vector<vector<int>> board2 = { {1, 1}, {1, 0} };
    Solution s2;
    s2.gameOfLife(board2);
    cout << "Solution 2:\n";
    s2.PrintBoard(board2); // [[1, 1], [1, 1]]


    return 0;
}

