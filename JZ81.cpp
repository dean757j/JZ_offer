/*
JZ81 调整数组顺序使奇数位于偶数前面(二)
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
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    vector<int> reOrderArrayTwo(vector<int>& array) {
        int i = 0;
        int j = array.size() - 1;
        while (i < j)
        {
            while (i < j && 0 != array[i] % 2)
                ++i;
            while (i < j && 0 == array[j] % 2)
                --j;
            swap(array[i], array[j]);
        }
        return array;
    }
};