/*
JZ17 打印从1到最大的n位数
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n) {
        int max = 1;
        int cnt = 0;
        while (cnt++ < n)
            max *= 10;
        vector<int> rst;
        for (int i = 1; i < max; ++i)
            rst.push_back(i);
        return rst;
    }
};