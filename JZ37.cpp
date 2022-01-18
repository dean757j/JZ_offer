/*
JZ37 序列化二叉树
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
    void PreOrder(TreeNode* root, string& rst)
    {
        if (root == nullptr)
        {
            rst += "#";
            return;
        }
        rst += to_string(root->val) + "!";
        PreOrder(root->left, rst);
        PreOrder(root->right, rst);
    }

    char* Serialize(TreeNode *root) {    
        string rst;
        PreOrder(root, rst);
        char* ans = new char[rst.size() + 1];
        strcpy(ans, rst.c_str());
        return ans;
    }

    TreeNode* DeserializeStr(char* str, int& index)
    {
        if (str[index] == '#')
        {
            ++index;
            return nullptr;
        }
        int val = 0;
        while (str[index] != '!')
        {
            val = val * 10 + str[index] - '0';
            ++index;
        }
        ++index;
        TreeNode* root = new TreeNode(val);
        root->left = DeserializeStr(str, index);
        root->right = DeserializeStr(str, index);
        return root;
    }

    TreeNode* Deserialize(char *str) {
        int index = 0;
        return DeserializeStr(str, index);
    }
};