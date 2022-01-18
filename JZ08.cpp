/*
JZ8 二叉树的下一个结点
*/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode)
            return nullptr;
        if (pNode->right)
        {
            pNode = pNode->right;
            while (pNode->left)
            {
                pNode = pNode->left;
            }
            return pNode;
        }
        while (pNode->next)
        {
            TreeLinkNode* p = pNode->next;
            if (p->left == pNode)
                return p;
            pNode = pNode->next;
        }
        return nullptr;
    }
};