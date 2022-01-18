/*
JZ83 剪绳子（进阶版）
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number long长整型 
     * @return long长整型
     */
    long long pow(long cnt)
    {
        if (cnt == 0)
            return 1;
        else if (cnt == 1)
            return 3;
        long long part = pow(cnt / 2);
        if (cnt % 2 == 0)
            return part * part % 998244353;
        return 3 * part * part % 998244353;
    }

    long long cutRope(long long number) {
        if (number == 2)
            return 1;
        else if (number == 3)
            return 2;
        long cnt = number / 3;
        if (number % 3 == 0)
            return pow(cnt) % 998244353;
        else if (number % 3 == 1)
        {
            --cnt;
            return 2 * 2 * pow(cnt) % 998244353;
        }
        else
            return 2 * pow(cnt) % 998244353;
    }
};