/*
JZ36 二叉搜索树与双向链表
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
    TreeNode* preNode;
    
    void ConvertNode(TreeNode* pRoot)
    {
        if (!pRoot)
            return;
        TreeNode* pCurrent = pRoot;
        if (pRoot->left)
            ConvertNode(pRoot->left);
        pCurrent->left = preNode;
        if (preNode)
            preNode->right = pCurrent;
        preNode = pCurrent;
        if (pRoot->right)
            ConvertNode(pRoot->right);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree)
            return pRootOfTree;
        preNode = nullptr;
        ConvertNode(pRootOfTree);
        while (preNode && preNode->left)
            preNode = preNode->left;
        return preNode;
    }
};