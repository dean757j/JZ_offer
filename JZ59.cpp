/*
JZ59 滑动窗口的最大值
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> rst;
        if (num.empty() || size < 1 || num.size() < size)
            return rst;
        deque<int> deQueue;
        for (int i = 0; i < num.size(); ++i)
        {
            while (!deQueue.empty() && num[i] > num[deQueue.back()])
                deQueue.pop_back();
            deQueue.push_back(i);
            if (deQueue.front() + size <= i)
                deQueue.pop_front();
            if (i + 1 >= size)
                rst.push_back(num[deQueue.front()]);
        }
        return rst;
    }
};