/*
JZ13 机器人的运动范围
*/
class Solution {
public:
    bool flag[201][201];
    const int dxy[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    int sumBit(int num)
    {
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
    void dfs(int x, int y, int& rows, int& cols, int& threshold, int& rst)
    {
        for (int i = 0; i < 4; ++i)
        {
            int dx = x + dxy[i][0];
            int dy = y + dxy[i][1];
            if (dx >= 0 && dx < rows && dy >= 0 && dy < cols && \
                    !flag[dx][dy] && (sumBit(dx) + sumBit(dy) <= threshold))
            {
                flag[dx][dy] = true;
                ++rst;
                dfs(dx, dy, rows, cols, threshold, rst);
            }
        }
    }

    int movingCount(int threshold, int rows, int cols) {
        int i = 0;
        int j = 0;
        memset(flag, 0, sizeof(flag));
        int rst = 0;
        if (i + j <= threshold)
        {
            flag[i][j] = true;
            ++rst;
            dfs(i, j, rows, cols, threshold, rst);
        }
        return rst;
    }
};