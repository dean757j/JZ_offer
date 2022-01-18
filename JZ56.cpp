/*
JZ56 数组中只出现一次的两个数字
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        vector<int> rst;
        int tmp = 0;
        for (int i = 0; i < array.size(); ++i)
            tmp ^= array[i];
        int mask = 1;
        while ((tmp & mask) == 0)
            mask  <<= 1;
        int rst1 = 0;
        int rst2 = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            if ((array[i] & mask) == 0)
                rst1 ^= array[i];
            else
                rst2 ^= array[i];
        }
        if (rst1 < rst2)
        {
            rst.push_back(rst1);
            rst.push_back(rst2);
        }
        else
        {
            rst.push_back(rst2);
            rst.push_back(rst1);
        }
        return rst;
    }
};