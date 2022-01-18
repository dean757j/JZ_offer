/*
JZ73 翻转单词序列
*/
class Solution {
public:
    string ReverseSentence(string str) {
        string rst = "";
        if (str.empty())
            return rst;
        string tmp = "";
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] != ' ')
                tmp += str[i];
            else
            {
                rst = " " + tmp + rst;
                tmp = "";
            }
        }
        if (!tmp.empty())
            rst = tmp + rst;
        return rst;
    }
};