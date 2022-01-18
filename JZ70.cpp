/*
JZ70 矩形覆盖
*/
class Solution {
public:
    int rectCover(int number) {
        if (number <= 2)
            return number;
        return rectCover(number - 1) + rectCover(number - 2);
    }
};