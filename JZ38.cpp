/*
JZ38 字符串的排列
*/
class Solution {
public:
    vector<string> rst;
    void swap(char& a, char& b)
    {
        char tmp = a;
        a = b;
        b = tmp;
    }

    void Perm(string str, int begin)
    {
        if (begin == str.length() - 1)
        {
            if (find(rst.begin(), rst.end(), str) == rst.end())
                rst.push_back(str);
        }
        else
        {
            for (int i = begin; i != str.length(); ++i)
            {
                swap(str[i], str[begin]);
                Perm(str, begin + 1);
                swap(str[i], str[begin]);
            }
        }
    }

    vector<string> Permutation(string str) {
        if (str.empty())
            return rst;
        Perm(str, 0);
        return rst;
    }
};