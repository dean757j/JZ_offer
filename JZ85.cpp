/*
JZ85 连续子数组的最大和(二)
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        vector<int> rst;
        vector<int> dp(array.size(), 0);
        dp[0] = array[0];
        int maxSum = array[0];
        int left = 0, right = 0;
        int leftM = 0, rightM = 0;
        for (right = 1; right < array.size(); ++right)
        {
            dp[right] = max(dp[right - 1] + array[right], array[right]);
            if (array[right] > dp[right - 1] + array[right])
                left = right;
            if (dp[right] > maxSum || (dp[right] == maxSum && (right - left) > (rightM - leftM)))
            {
                maxSum = dp[right];
                leftM = left;
                rightM = right;
            }
        }
        for (int i = leftM; i <= rightM; ++i)
            rst.push_back(array[i]);
        return rst;
    }
};