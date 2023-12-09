#include <iostream>
#include <climits>
#include <limits>
using namespace std;

//Definition for a binary tree node.

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int lastElement = INT_MIN;
bool firstElement = false;

class Solution 
{

    bool isValidBST_(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        
        bool a = isValidBST_(root->left);
        if (firstElement && lastElement >= root->val)
            return false;
        lastElement = root->val;
        firstElement = true;
        bool b = isValidBST_(root->right);

        return (a && b);
    }

public:
    bool isValidBST(TreeNode* root) 
    {
        bool isValid = isValidBST_(root); // O(n)
        
        lastElement = INT_MIN;
        firstElement = false;
        
        return isValid;
    }

    void Print_Tree_InOrder(TreeNode* root)
    {
        if (root == nullptr)
            return;

        Print_Tree_InOrder(root->left);
        cout << root->val << " ";
        Print_Tree_InOrder(root->right);
    }
};

int main()
{
    // Time Complexity: O(n) -- Traversal of BST InOrder.
    //
    // Example 1:
    TreeNode* t1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    Solution s1;
    cout << "Solution 1:\n";
    cout << s1.isValidBST(t1) << endl << endl; // True
    s1.Print_Tree_InOrder(t1);
    cout << endl << endl;

    // Example 2:
    TreeNode* t2 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    Solution s2;
    cout << "Solution 2:\n";
    cout << s2.isValidBST(t2) << endl << endl; // False
    s2.Print_Tree_InOrder(t2);
    cout << endl << endl;

    return 0;
}
