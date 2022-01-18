/*
JZ46 把数字翻译成字符串
*/
class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        if (nums.empty() || nums[0] == '0')
            return 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] != '0')
                dp[i] = dp[i - 1];
            int tmp = nums[i] - '0' + 10 * (nums[i - 1] - '0');
            if (tmp >= 10 && tmp <= 26)
            {
                if (i == 1)
                    ++dp[i];
                else
                    dp[i] += dp[i - 2];
            }
        }
        return dp[n - 1];
    }
};