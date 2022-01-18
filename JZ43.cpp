/*
JZ43 整数中1出现的次数（从1到n整数中1出现的次数）
*/
class Solution {
public:
    int NumberOf1(int n)
    {
        int sum = 0;
        while (n)
        {
            if (n % 10 == 1)
                ++sum;
            n /= 10;
        }
        return sum;
    }

    int NumberOf1Between1AndN_Solution(int n) {
        int num = 0;
        for (int i = 1; i <= n; ++i)
            num += NumberOf1(i);
        return num;
    }
};