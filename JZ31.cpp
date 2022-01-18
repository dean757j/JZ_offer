/*
JZ31 栈的压入、弹出序列
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool bPossible = false;
        stack<int> data;
        if (!pushV.empty() && !popV.empty())
        {
            int i = 0, j = 0;
            while (i < pushV.size())
            {
                if (pushV[i] != popV[j])
                    data.push(pushV[i++]);
                else
                {
                    ++i;
                    ++j;
                    while (!data.empty() && data.top() == popV[j])
                    {
                        ++j;
                        data.pop();
                    }
                }
            }
        }
        if (data.empty())
            bPossible = true;
        return bPossible;
    }
};
