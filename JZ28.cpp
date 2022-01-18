/*
JZ28 对称的二叉树
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSame(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }

    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot)
            return true;
        return isSame(pRoot->left, pRoot->right);
    }

};