/*
JZ44 数字序列中某一位的数字
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int findNthDigit(int n) {
        if (n <= 0)
            return 0;
        long start  = 1;
        long digits = 1;
        long count = 9;
        while (n > count)
        {
            n -= count;
            start *= 10;
            ++digits;
            count = start * digits * 9;
        }
        string num = to_string(start + (n - 1) / digits);
        int index = (n - 1) % digits;
        return int(num[index] - '0');
    }
};