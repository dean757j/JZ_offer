/*
JZ71 跳台阶扩展问题
*/
class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 1)
            return number;
        return 1 << (number - 1);
    }
};