/*
JZ19 正则表达式匹配
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        int m = str.size();
        int n = pattern.size();
        bool dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 0; i < n; ++i)
        {
            if (pattern[i] == '*' && dp[0][i - 1])
                dp[0][i + 1] = true;
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (str[i] == pattern[j] || pattern[j] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                else if (pattern[j] == '*')
                {
                    if (pattern[j - 1] == str[i] || pattern[j - 1] == '.')
                        dp[i + 1][j + 1] = dp[i][j + 1];
                    dp[i + 1][j + 1] |= dp[i + 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};