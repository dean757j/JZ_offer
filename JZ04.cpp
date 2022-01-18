/*
JZ4 二维数组中的查找
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty())
            return false;
        int rows = array.size();
        int columns = array[0].size();
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            if (array[row][column] == target)
                return true;
            else if (array[row][column] < target)
                ++row;
            else
                --column;
        }
        return false;
    }
};
