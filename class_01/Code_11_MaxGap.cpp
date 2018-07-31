#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <stdio.h>


using namespace std;

// 给定一个数组，求如果排序之后，相邻两数的最大差值，要求时间复杂度为o(N)
class Code_11_MaxGap
{

  public:
    // 给定一个数，判断所属于的桶
    static int bucket(long num, long len, long min_v, long max_v)
    {
        return (int)((num - min_v) * len / (max_v - min_v));
    }

    static int maxGap(int *arr, int len)
    {
        if (arr == NULL || len < 2)
        {
            return 0;
        }
        int min_v = INT32_MAX;
        int max_v = INT32_MIN;

        for (int i = 0; i < len; i++)
        {
            min_v = min(min_v, arr[i]);
            max_v = max(max_v, arr[i]);
        }
        if (min_v == max_v)
        {
            return 0;
        }

        //判断每一个桶是否有数字
        bool *has = new bool[len + 1]();
        // 记录每个桶的最大值和最小值
        int *maxs = new int[len + 1]();
        int *mins = new int[len + 1]();

        int index = 0;
        for (int i = 0; i < len; i++)
        {
            index = bucket(arr[i], len, min_v, max_v);
            mins[index] = has[index] ? min(mins[index], arr[i]) : arr[i];
            maxs[index] = has[index] ? max(mins[index], arr[i]) : arr[i];
            has[index] = true;
        }

        int res = 0;
        int lastMax = maxs[0];
        int i = 1;
        for (; i <= len; i++)
        {
            if (has[i])
            {
                res = max(res, mins[i] - lastMax);
                lastMax = maxs[i];
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    int arr[10] = {1, 2, 3, 55, 56, 57, 58, 59, 100, 1001};
    cout << Code_11_MaxGap::maxGap(arr, 10) << endl;
    getchar();
    return 0;
}
