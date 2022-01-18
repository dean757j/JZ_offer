/*
JZ61 扑克牌顺子
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.empty())
            return false;
        sort(numbers.begin(), numbers.end());
        int numZero = 0;
        for (int i = 0; i < numbers.size() && numbers[i] == 0; ++i)
            ++numZero;
        int numGap = 0;
        int start = numZero;
        int end = start + 1;
        while (end < numbers.size())
        {
            if (numbers[start] == numbers[end])
                return false;
            else
                numGap += numbers[end] - numbers[start] - 1;
            start = end;
            ++end;
        }
        return numZero < numGap ? false : true;
    }
};