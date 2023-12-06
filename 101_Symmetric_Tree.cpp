#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
//
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//

class Solution
{
    vector<pair<int, bool>> sol_inorder; // left -> "0", right -> "1".

    void inorder_(TreeNode* root, const bool path)
    {
        if (root == nullptr)
            return;
            
        inorder_(root->left, 0);
        this->sol_inorder.push_back(make_pair(root->val, path));
        inorder_(root->right, 1);
    }

public:
    bool isSymmetric(TreeNode* root)
    {
        this->inorder_(root, 0);

        const int sz_sol = this->sol_inorder.size();
        
        for (int i = 0; i < sz_sol >> 1; i++)
        {
            if (this->sol_inorder[i].first != this->sol_inorder[(sz_sol - 1) - i].first || this->sol_inorder[i].second == this->sol_inorder[(sz_sol - 1) - i].second)
                return false;
        }
        return true;
    }

    void PrintSol()
    {
        const int sz = this->sol_inorder.size();
        for (int i = 0; i < sz; i++)
        {
            cout << this->sol_inorder[i].first << " " << this->sol_inorder[i].second << endl;
        }
        cout << "\n";
    }
};

int main()
{
    // Time Complexity: O(n) - Inorder Traversal in a Binary Tree.
    //  
    // Example 1:
    TreeNode* root1 = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
    Solution s1;
    cout << "Output 1: " << s1.isSymmetric(root1) << endl; // True
    cout << "Solution 1:\n";
    s1.PrintSol(); // [3, 2, 4, 1, 4, 2, 3]

    // Example 2:
    TreeNode* root2 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3)));
    Solution s2;
    cout << "Output 2: " << s2.isSymmetric(root2) << endl; // False
    cout << "Solution 2:\n";
    s2.PrintSol(); // [2, 3, 1, 2, 3]

    return 0;
}