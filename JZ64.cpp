/*
JZ64 求1+2+3+...+n
*/
class Solution {
public:
    int Sum_Solution(int n) {
        bool flag = n > 1 && (n += Sum_Solution(n - 1));
        return n;
    }
};