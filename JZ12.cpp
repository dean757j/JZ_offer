/*
JZ12 矩阵中的路径
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool flag[201][201];
    int rows, cols;
    const int dxy[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    bool dfs(vector<vector<char>>& matrix, int x, int y, int index, string& word)
    {
        if (index == word.size())
            return true;
        flag[x][y] = true;
        for (int i = 0; i < 4; ++i)
        {
            int dx = x + dxy[i][0];
            int dy = y + dxy[i][1];
            if (dx >= 0 && dx < rows && dy >= 0 && dy < cols && \
                !flag[dx][dy] && matrix[dx][dy] == word[index])
            {
                if (dfs(matrix, dx, dy, index + 1, word))
                    return true;
                flag[dx][dy] = false;
             }
        }
        return false;
    }

    bool hasPath(vector<vector<char> >& matrix, string word) {
        rows = matrix.size();
        cols = matrix[0].size();
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (word[0] == matrix[i][j])
                {
                    if (dfs(matrix, i, j, 1, word))
                        return true;
                    flag[i][j] = false;
                }
            }
        }
        return false;
    }
};