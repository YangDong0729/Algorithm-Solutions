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
    int sumNumbers(TreeNode *root) {
        return _sumNumbers(root, 0);
    }

    int _sumNumbers(TreeNode *root, int number) {
        if (!root)
            return 0;
        number = number * 10 + root->val;
        if (!root->left && !root->right)
            return number;
        return _sumNumbers(root->left, number) + _sumNumbers(root->right, number);
    }
};