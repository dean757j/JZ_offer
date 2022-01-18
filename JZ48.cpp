/*
JZ48 最长不含重复字符的子字符串
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> m;
        int rst = 0;
        int left = 0;
        int right = 0;
        while (right < s.size())
        {
            if (m.find(s[right]) != m.end())
                left = left > (m[s[right]] + 1) ? left : (m[s[right]] + 1);
            m[s[right]] = right;
            ++right;
            rst = rst > (right - left) ? rst: (right - left);
        }
        return rst;
    }
};