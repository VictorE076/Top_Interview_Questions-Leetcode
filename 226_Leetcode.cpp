#include <iostream>

using namespace std;

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == nullptr)
            return nullptr;

        TreeNode* oldLeftChild = root->left;

        root->left = invertTree(root->right);
        root->right = invertTree(oldLeftChild);

        return root;
    }

    //
    void printTreeInOrder(TreeNode* root) {
        
        if (root == nullptr)
            return;

        printTreeInOrder(root->left);

        cout << root->val << " ";

        printTreeInOrder(root->right);
    }

    void printTreePreOrder(TreeNode* root) {

        if (root == nullptr)
            return;

        cout << root->val << " ";

        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
};

int main()
{
    // Time Complexity: O(n) - swapping both TreeNode children nodes in constant time.
    //
    // Example 1:
    TreeNode* root1 = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    Solution s1;
    TreeNode* sol1 = s1.invertTree(root1); // [4, 7, 2, 9, 6, 3, 1]
    cout << "Solution 1:  ";
    s1.printTreePreOrder(sol1);
    cout << " ";
    s1.printTreeInOrder(sol1);
    cout << "\n\n";


    // Example 2:
    TreeNode* root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    Solution s2;
    TreeNode* sol2 = s2.invertTree(root2); // [2, 3, 1]
    cout << "Solution 2:  ";
    s2.printTreePreOrder(sol2);
    cout << " ";
    s2.printTreeInOrder(sol2);
    cout << "\n\n";


    // Example 3:
    TreeNode* root3 = nullptr;
    Solution s3;
    TreeNode* sol3 = s3.invertTree(root3); // []
    cout << "Solution 3:  ";
    s3.printTreePreOrder(sol3);
    cout << " ";
    s3.printTreeInOrder(sol3);
    cout << "\n\n";

    return 0;
}