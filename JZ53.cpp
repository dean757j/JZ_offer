/*
JZ53 数字在升序数组中出现的次数
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int first = 0;
        int last = 0;
        int start = 0;
        int end = data.size();
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (data[mid] < k)
                start = mid + 1;
            else
                end = mid;
        }
        first = start;
        start = 0;
        end = data.size();
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (data[mid] <= k)
                start = mid + 1;
            else
                end = mid;
        }
        last = start;
        return last - first;
    }
};