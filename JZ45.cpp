/*
JZ45 把数组排成最小的数
*/
class Solution {
public:
    static bool cmp(string s1, string s2)
    {
        return s1 + s2 < s2 + s1;
    }

    string PrintMinNumber(vector<int> numbers) {
        string rst = "";
        if (numbers.empty())
            return rst;
        vector<string> tmp;
        for (int i = 0; i < numbers.size(); ++i)
            tmp.push_back(to_string(numbers[i]));
        sort(tmp.begin(), tmp.end(), cmp);
        for (int i = 0; i < tmp.size(); ++i)
            rst += tmp[i];
        return rst;
    }
};