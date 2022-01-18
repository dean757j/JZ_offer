/*
JZ67 把字符串转换成整数(atoi)
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
    int StrToInt(string s) {
        if (s.empty())
            return 0;
        long rst = 0;
        int sig = 1;
        int i = 0;
        while (s[i] == ' ')
            ++i;
        if (s[i] == '+')
            ++i;
        else if (s[i] == '-')
        {
            ++i;
            sig = -1;
        }
        while (s[i] != '\0')
        {
            if (s[i] < '0' || s[i] > '9')
                break;
            rst = rst * 10 + sig * (s[i] - '0');
            if (sig == 1 && rst > 0x7FFFFFFF)
            {
                rst = 0x7FFFFFFF;
                break;
            }
            if (sig == -1 && rst < (signed int)0x80000000)
            {
                rst = 0x80000000;
                break;
            }
            ++i;
        }
        return rst;
    }
};