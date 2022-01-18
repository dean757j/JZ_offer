/*
JZ5 替换空格
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        if (0 == s.size())
            return "";
        
        int i = 0;
        int length = 0, blankCnt = 0;
        while (s[i] != '\0')
        {
            if (s[i] == ' ')
            {
                ++blankCnt;
                s += "00";
            }
            ++length;
            ++i;
        }

        int src = length - 1;
        int dst = length - 1 + 2 * blankCnt;
        while (src >= 0 && dst > src)
        {
            if (s[src] == ' ')
            {
                s[dst--] = '0';
                s[dst--] = '2';
                s[dst--] = '%';
            }
            else
                s[dst--] = s[src];
            --src;
        }
        return s;
    }
};