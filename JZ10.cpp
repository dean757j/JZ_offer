/*
JZ10 斐波那契数列
*/
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 0)
            return 0;
        else if (n == 1)
            return 1;

        int FibMinTwo = 0;
        int FibMinOne = 1;
        int FibN = 0;
        for (int i = 2; i <= n; ++i)
        {
            FibN = FibMinOne + FibMinTwo;
            FibMinTwo = FibMinOne;
            FibMinOne = FibN;
        }
        return FibN;
    }
};