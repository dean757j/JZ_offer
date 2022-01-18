/*
JZ39 数组中出现次数超过一半的数字
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())
            return 0;
        int cond = -1;
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (cnt == 0)
            {
                cond = numbers[i];
                cnt = 1;
            }
            else
            {
                if (cond == numbers[i])
                    ++cnt;
                else
                    --cnt;
            }
        }
        cnt = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            if (cond == numbers[i])
                ++cnt;
        }
        if (cnt > numbers.size() / 2)
            return cond;
        return 0;
    }
};