/*
JZ74 和为S的连续正数序列
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> rst;
        if (sum < 3)
            return rst;
        int start = 1;
        int end = 2;
        int startMax = (1 + sum) / 2;
        int tmpSum = start + end;
        while (start < startMax)
        {
            if (tmpSum == sum)
            {
                vector<int> tmp;
                for (int i = start; i <= end; ++i)
                    tmp.push_back(i);
                rst.push_back(tmp);
                ++end;
                tmpSum += end;
            }
            else if (tmpSum > sum)
            {
                tmpSum -= start;
                ++start;
            }
            else
            {
                ++end;
                tmpSum += end;
            }
        }
        return rst;
    }
};