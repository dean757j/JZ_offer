/*
JZ11 旋转数组的最小数字
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        int index1 = 0;
        int index2 = rotateArray.size() - 1;
        int indexMid = index1;

        while (rotateArray[index1] >= rotateArray[index2])
        {
            if (1 == index2 - index1)
            {
                indexMid = index2;
                break;
            }

            indexMid = (index1 + index2) / 2;
            if (rotateArray[index1] == rotateArray[index2] && \
                rotateArray[index1] == rotateArray[indexMid])
            {
                for (int i = index1; i <= index2; ++i)
                {
                    if (rotateArray[i] < rotateArray[indexMid])
                        indexMid = i;
                }
                break;
            }
            if (rotateArray[indexMid] >= rotateArray[index1])
                index1 = indexMid;
            else if (rotateArray[indexMid <= rotateArray[index2]])
                index2 = indexMid;
        }
        return rotateArray[indexMid];
    }
};
