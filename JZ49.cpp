/*
JZ49 丑数
*/
class Solution {
public:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }

    int GetUglyNumber_Solution(int index) {
        vector<int> ugly;
        ugly.push_back(1);
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        for (int i = 1; i < index; ++i)
        {
            int num = min(ugly[index2] * 2, min(ugly[index3] * 3, ugly[index5] * 5));
            ugly.push_back(num);
            if (num == ugly[index2] * 2)
                ++index2;
            if (num == ugly[index3] * 3)
                ++index3;
            if (num == ugly[index5] * 5)
                ++index5;
        }
        return ugly[index - 1];
    }
};