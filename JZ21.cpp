/*
JZ21 调整数组顺序使奇数位于偶数前面(一)
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
    vector<int> reOrderArray(vector<int>& array) {
        if (array.empty())  
            return array;
        int i = 0;
        for (int j = 0; j < array.size(); ++j)
        {
            if (array[j] % 2 != 0)
            {
                int tmp = array[j];
                for (int k = j; k > i; --k)
                    array[k] = array[k - 1];
                array[i++] = tmp;
            }
        }
        return array;
    }
};