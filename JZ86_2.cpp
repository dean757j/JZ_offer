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
    bool GetNodePath(TreeNode* root, int val, list<TreeNode*>& path)
    {
        if (!root)
            return false;
        path.push_back(root);
        if (root->val == val)
            return true;
        path.push_back(root);
        bool left = false;
        bool right = false;
        left = GetNodePath(root->left, val, path);
        right = GetNodePath(root->right, val, path);
        if (!left && !right)
            path.pop_back();
        return left || right;
    }

    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        if (root == nullptr)
            return -1;
        list<TreeNode*> path1;
        GetNodePath(root, o1, path1);
        list<TreeNode*> path2;
        GetNodePath(root, o2, path2);
        auto i1 = path1.begin();
        auto i2 = path2.begin();
        TreeNode* rst;
        while (i1 != path1.end() && i2 != path2.end())
        {
            if (*i1 == *i2)
                rst = *i1;
            ++i1;
            ++i2;
        }
        return rst->val;
    }
};