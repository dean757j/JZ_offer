/*
JZ50 第一个只出现一次的字符
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
            return 0;
        int cnt[256] = {0};
        for (int i = 0; i < str.length(); ++i)
            ++cnt[str[i]];
        for (int i = 0; i < str.length(); ++i)
        {
            if (1 == cnt[str[i]])
                return i;
        }
        
        return -1;
    }
};
