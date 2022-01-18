/*
JZ86 在二叉树中找到两个节点的最近公共祖先
*/
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    TreeNode* GetNode(TreeNode* root, int o1, int o2)
    {
        if (root == nullptr || root->val == o1 || root->val == o2)
            return root;
        TreeNode* left = GetNode(root->left, o1, o2);
        TreeNode* right = GetNode(root->right, o1, o2);
        if (left && right)
            return root;
        if (left)
            return left;
        if (right)
            return right;
        return nullptr;
    }

    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        if (root == nullptr)
            return -1;
        TreeNode* pRoot = GetNode(root, o1, o2);
        if (pRoot)
            return pRoot->val;
        return -1;
    }
};