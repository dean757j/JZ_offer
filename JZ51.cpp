/*
JZ51 数组中的逆序对
*/
class Solution {
public:
    const int kmod = 1000000007;

    void Merge(vector<int>& arr, vector<int>& tmp, int left, int mid, int right, int& rst)
    {
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right)
        {
            if (arr[i] > arr[j])
            {
                tmp[k++] = arr[j++];
                rst += (mid - i + 1);
                rst %= kmod;
            }
            else
                tmp[k++] = arr[i++];
        }
        while (i <= mid)
            tmp[k++] = arr[i++];
        while (j <= right)
            tmp[k++] = arr[j++];
        for (k = 0, i = left; i <= right; ++i, ++k)
            arr[i] = tmp[k];
    }

    void MergeSort(vector<int>& arr, vector<int>& tmp, int left, int right, int& rst)
    {
        if (left == right)
            return;
        int mid = left + ((right - left) >> 1);
        MergeSort(arr, tmp, left, mid, rst);
        MergeSort(arr, tmp, mid + 1, right, rst);
        Merge(arr, tmp, left, mid, right, rst);
    }

    int InversePairs(vector<int> data) {
        int rst = 0;
        vector<int> tmp(data.size());
        MergeSort(data, tmp, 0, data.size() - 1, rst);
        return rst;
    }
};