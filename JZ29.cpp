/*
JZ29 顺时针打印矩阵
*/
class Solution {
public:
    void print(int lx, int ly, int rx, int ry, vector<vector<int>> matrix, vector<int>& rst)
    {
        for (int i = ly; i <= ry; ++i)
            rst.push_back(matrix[lx][i]);
        if (lx < rx)
            for (int i = lx + 1; i <= rx; ++i)
                rst.push_back(matrix[i][ry]);
        if (ry > ly && rx > lx)
            for (int i = ry - 1; i >= ly; --i)
                rst.push_back(matrix[rx][i]);
        if (rx > lx + 1 && ry > ly)
            for (int i = rx - 1; i >= lx + 1; --i)
                rst.push_back(matrix[i][ly]);
    }

    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> rst;
        if (matrix.empty())
            return rst;
        int lx = 0, ly = 0;
        int rx = matrix.size() - 1;
        int ry = matrix[0].size() - 1;
        while (lx <= rx && ly <= ry)
            print(lx++, ly++, rx--, ry--, matrix, rst);
        return rst;
    }
};