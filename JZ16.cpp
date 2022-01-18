/*
JZ16 数值的整数次方
*/
class Solution {
public:
    double Power(double base, int exponent) {
        if ((base - 0.0 > -0.0000001) && (base - 0.0 < 0.0000001))
            return 0;
        long long p = abs((long long)exponent);
        double r = 1.0;
        while(p)
        {
            if (p & 1)
                r *= base;
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1/ r : r;
    }
};