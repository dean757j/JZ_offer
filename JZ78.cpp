/*
JZ78 把二叉树打印成多行
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
            queue<TreeNode*> q;
            q.push(pRoot);
            while (!q.empty())
            {
                vector<int> tmp;
                int n = q.size();
                for (int i = 0; i < n; ++i)
                {
                    TreeNode* p = q.front();
                    q.pop();
                    if (p->left)
                        q.push(p->left);
                    if (p->right)
                        q.push(p->right);
                    tmp.push_back(p->val);
                }
                if (!tmp.empty())
                    rst.push_back(tmp);
                tmp.clear();
            }
            return rst;
        }
    
};