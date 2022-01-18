/*
JZ34 二叉树中和为某一值的路径(二)
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
    vector<vector<int>> rst;
    vector<int> path;

    void FindNode(TreeNode* root,int num)
    {
        path.push_back(root->val);
        if (!root->left && !root->right && num == root->val)
            rst.push_back(path);
        if (root->left)
            FindNode(root->left, num - root->val);
        if (root->right)
            FindNode(root->right, num - root->val);
        path.pop_back();
    }

    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        if (nullptr == root)
            return rst;
        FindNode(root, expectNumber);
        return rst;
    }
};