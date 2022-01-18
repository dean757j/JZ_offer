/*
JZ20 表示数值的字符串
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool isNumeric(string str) {
        if (str.empty())
            return false;
        int len = str.size();
        bool hasNum = false;
        bool hasE = false;
        bool hasSign = false;
        bool hasDot = false;
        int i = 0;
        while (i < len && str[i] == ' ')
            ++i;
        while (i < len)
        {
            while (i < len && str[i] >= '0' && str[i] <= '9')
            {
                hasNum = true;
                ++i;
            }
            if (i == len)
                break;
            char c = str[i];
            if (c == 'E' || c == 'e')
            {
                if (hasE || !hasNum)
                    return false;
                hasE = true;
                hasNum = false;
                hasSign = false;
                hasDot = false;
            }
            else if (c == '+' || c == '-')
            {
                if (hasSign || hasNum || hasDot)
                    return false;
                hasSign = true;
            }
            else if (c == '.')
            {
                if (hasDot || hasE)
                    return false;
                hasDot = true;
            }
            else if (c == ' ')
                break;
            else
                return false;
            ++i;
        }
        while (i < len && str[i] == ' ')
            ++i;
        return hasNum && i == len;        
    }
};