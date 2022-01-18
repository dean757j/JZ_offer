/*
JZ77 按之字形顺序打印二叉树
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> rst;
        if (!pRoot)
            return rst;
        stack<TreeNode*> stk1, stk2;
        stk1.push(pRoot);
        while (!stk1.empty() || !stk2.empty())
        {
            vector<int> tmp;
            while (!stk1.empty())
            {
                TreeNode* p = stk1.top();
                stk1.pop();
                tmp.push_back(p->val);
                if (p->left)
                    stk2.push(p->left);
                if (p->right)
                    stk2.push(p->right);
            }
            if (!tmp.empty())
                rst.push_back(tmp);
            tmp.clear();
            while (!stk2.empty())
            {
                TreeNode* p = stk2.top();
                stk2.pop();
                tmp.push_back(p->val);
                if (p->right)
                    stk1.push(p->right);
                if (p->left)
                    stk1.push(p->left);
            }
            if (!tmp.empty())
                rst.push_back(tmp);
        }
        return rst;
    }
    
};