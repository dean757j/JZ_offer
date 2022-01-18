/*
JZ54 二叉搜索树的第k个节点
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
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int count = 0;
    int rst =  -1;

    int KthNode(TreeNode* proot, int k) {
        if (!proot || k <= 0)
            return -1;
        KthNode(proot->left, k);
        ++count;
        if (count == k)
            rst = proot->val;
        KthNode(proot->right, k);
        return rst;
    }
};