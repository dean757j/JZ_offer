/*
JZ41 数据流中的中位数
*/
class Solution {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void Insert(int num) {
        if (maxHeap.empty() || maxHeap.top() > num)
            maxHeap.push(num);
        else
            minHeap.push(num);
        int a = maxHeap.size();
        int b = minHeap.size();
        if (a - b > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (a < b)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double GetMedian() { 
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        return (double)maxHeap.top();
    }

};