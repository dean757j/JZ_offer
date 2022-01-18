/*
JZ62 孩子们的游戏(圆圈中最后剩下的数)
*/
class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n < 1)
            return -1;
        int rst = 0;
        for (int i = 2; i <= n; ++i)
            rst = (rst + m) % i;
        return rst;
    }
};