/*
JZ63 买卖股票的最好时机(一)
*/
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int min = 10001;
        int rst = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < min)
                min = prices[i];
            else if (prices[i] - min > rst)
                rst = prices[i] - min;
        }
        return rst;
    }
};