#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
//
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//

class Solution 
{
    vector<int> sol_inorder;

    void inorder_(TreeNode* root)
    {
        if (root == nullptr)
            return;

        inorder_(root->left);
        this->sol_inorder.push_back(root->val);
        inorder_(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        this->inorder_(root);
        return this->sol_inorder;
    }

    void PrintSol()
    {
        const int sz = this->sol_inorder.size();
        for (int i = 0; i < sz; i++)
        {
            cout << this->sol_inorder[i] << " ";
        }
        cout << "\n\n";
    }
};

int main()
{
    // Time Complexity: O(n) - Inorder Traversal in a Binary Tree.
    //  
    // Example 1:
    TreeNode* root1 = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    Solution s1;
    s1.inorderTraversal(root1);
    cout << "Solution 1:\n";
    s1.PrintSol(); // [1, 3, 2]

    // Example 2:
    TreeNode* root2 = nullptr;
    Solution s2;
    s2.inorderTraversal(root2);
    cout << "Solution 2:\n";
    s2.PrintSol(); // []

    // Example 3:
    TreeNode* root3 = new TreeNode(1);
    Solution s3;
    s3.inorderTraversal(root3);
    cout << "Solution 3:\n";
    s3.PrintSol(); // [1]

    return 0;
}

