/*
JZ26 树的子结构
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool IsEqual(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2)
            return true;
        if (!pRoot1)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return IsEqual(pRoot1->left, pRoot2->left) && \
                IsEqual(pRoot1->right, pRoot2->right);
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        bool rst = false;
        if (pRoot1 && pRoot2)
        {
            if (pRoot1->val == pRoot2->val)
                rst = IsEqual(pRoot1, pRoot2);
            if (!rst)
                rst = HasSubtree(pRoot1->left, pRoot2);
            if (!rst)
                rst = HasSubtree(pRoot1->right, pRoot2);
        }
        return rst;
    }
};