/*
JZ57 和为S的两个数字
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> rst;
        if (array.empty())
            return rst;
        int start = 0;
        int end = array.size() - 1;
        while (start < end)
        {
            if (sum == array[start] + array[end])
            {
                rst.push_back(array[start]);
                rst.push_back(array[end]);
                break;
            }
            else if(sum < array[start] + array[end])
                --end;
            else
                ++start;
        }
        return rst;
    }
};