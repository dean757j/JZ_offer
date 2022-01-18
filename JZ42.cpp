/*
JZ42 连续子数组的最大和
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty())
            return 0;
        int sum = array[0];
        int maxSum = array[0];
        for (int i = 1; i < array.size(); ++i)
        {
            if (sum < 0)
                sum = array[i];
            else
                sum += array[i];
            if (sum > maxSum)
                maxSum = sum;
        }
        return maxSum;
    }
};