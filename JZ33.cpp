/*
JZ33 二叉搜索树的后序遍历序列
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        int len = sequence.size();
        int root = sequence[len - 1];
        int i = 0;
        vector<int> leftV, rightV;
        for (i = 0; i < len - 1; ++i)
        {
            if (sequence[i] > root)
                break;
            else
                leftV.push_back(sequence[i]);
        }
        for (; i < len - 1; ++i)
        {
            if (sequence[i] < root)
                return false;
            else
                rightV.push_back(sequence[i]);
        }
        bool left = true;
        bool right = true;
        if (leftV.size() > 1)
            left = VerifySquenceOfBST(leftV);
        if (rightV.size() > 1)
            right = VerifySquenceOfBST(rightV);
        return left && right;
    }
};