/*
JZ69 跳台阶
*/
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 2)
            return number;
        else
        {
            int f1 = 1;
            int f2 = 2;
            int rst;
            for (int i = 3; i <= number; ++i)
            {
                rst = f1 + f2;
                f1 = f2;
                f2 = rst;
            }
            return rst;
        }
    }
};