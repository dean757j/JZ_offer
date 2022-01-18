/*
JZ58 左旋转字符串
*/
class Solution {
public:
    void Reverse(string& str, int begin, int end)
    {
        while (begin < end)
        {
            char tmp = str[begin];
            str[begin] = str[end];
            str[end] = tmp;
            ++begin;
            --end;
        }
    }

    string LeftRotateString(string str, int n) {
        if (str.empty() || !n)
            return str;
        if (n % str.length() == 0)
            return str;
        if (n > str.length())
            n %= str.length();
        Reverse(str, 0, n - 1);
        Reverse(str, n, str.length() - 1);
        Reverse(str, 0, str.length() - 1);
        return str;
    }
};