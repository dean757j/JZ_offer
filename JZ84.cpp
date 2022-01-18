/*
JZ84 二叉树中和为某一值的路径(三)
*/
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型
     */
    int key = 0;

    void dfs(TreeNode* root, int sum)
    {
        if (!root)
            return;
        if (sum == root->val)
            ++key;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }

    int FindPath(TreeNode* root, int sum) {
        if (!root)
            return key;
        dfs(root, sum);
        FindPath(root->left, sum);
        FindPath(root->right, sum);
        return key;
    }
};