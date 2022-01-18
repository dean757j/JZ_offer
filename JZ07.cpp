/*
JZ7 重建二叉树
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty())
            return NULL;
        
        TreeNode* head = new TreeNode(pre[0]);
        head->left = NULL;
        head->right = NULL;
        int root = 0;
        for (int i = 0; i < vin.size(); ++i)
        {
            if (vin[i] == pre[0])
            {
                root = i;
                break;
            }
        }

        vector<int> preLeft, vinLeft, preRight, vinRight;
        for (int i = 0; i < root; ++i)
        {
            preLeft.push_back(pre[i + 1]);
            vinLeft.push_back(vin[i]);
        }
        for (int i = root + 1; i < pre.size(); ++i)
        {
            preRight.push_back(pre[i]);
            vinRight.push_back(vin[i]);
        }
        head->left = reConstructBinaryTree(preLeft, vinLeft);
        head->right = reConstructBinaryTree(preRight, vinRight);
        return head;
    }
};