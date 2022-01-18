/*
JZ75 字符流中第一个不重复的字符
*/
class Solution
{
public:
    unordered_map<char, int> mp;
    queue<char> q;
  //Insert one char from stringstream
    void Insert(char ch) {
        if (mp.find(ch) == mp.end())
            q.push(ch);
        ++mp[ch];
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        while (!q.empty())
        {
            if (mp[q.front()] == 1)
                return q.front();
            else
                q.pop();
        }
        return '#';
    }

};