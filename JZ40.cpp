/*
JZ40 最小的K个数
*/
class Solution {
public:
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int Partition(vector<int>& input, int low, int high)
    {
        int pivot = input[low];
        while (low < high)
        {
            while (low < high && input[high] >= pivot)
                --high;
            swap(input[low], input[high]);
            while (low < high && input[low] <= pivot)
                ++low;
            swap(input[low], input[high]);
        }
        return low;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> rst;
        if(input.empty() || k > input.size() || k <= 0)
            return rst;
        int low = 0;
        int high = input.size() - 1;
        int index = Partition(input, low, high);
        while (index != k - 1)
        {
            if (index > k - 1)
            {
                high = index - 1;
                index = Partition(input, low, high);
            }
            else
            {
                low = index + 1;
                index = Partition(input, low, high);
            }
        }
        for (int i = 0; i < k; ++i)
            rst.push_back(input[i]);
        return rst;
    }
};