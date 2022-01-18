/*
JZ79 判断是不是平衡二叉树
*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot)
            return 0;
        int left = TreeDepth(pRoot->left);
        if (left == -1)
            return -1;
        int right = TreeDepth(pRoot->right);
        if (right == -1)
            return -1;
        int diff = abs(left - right);
        if (diff > 1)
            return -1;
        return left > right ? (left + 1) : (right + 1);
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        return TreeDepth(pRoot) != -1;
    }
};