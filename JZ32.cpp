/*
JZ32 从上往下打印二叉树
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> rst;
        queue<TreeNode*> queueTreeNode;
        if (nullptr == root)
            return rst;
        queueTreeNode.push(root);
        while (!queueTreeNode.empty())
        {
            TreeNode* pNode = queueTreeNode.front();
            queueTreeNode.pop();
            rst.push_back(pNode->val);
            if (pNode->left)
                queueTreeNode.push(pNode->left);
            if (pNode->right)
                queueTreeNode.push(pNode->right);
        }
        return rst;
    }
};