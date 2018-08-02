#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

// 在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和
// 本质是归并排序的变种
class Code_12_smallSum

{
  public:
    static int mergeSort(int *arr, int n)
    {
        return merge_sort(arr, 0, n - 1);
    }
    static int merge_sort(int *arr, int l, int r)
    {
        if (l == r)
            return 0;
        int mid = l + (r - l) / 2;
        return merge_sort(arr, l, mid) +
               merge_sort(arr, mid + 1, r) +
               merge(arr, l, mid, r);
    }

    static int merge(int *arr, int l, int mid, int r)
    {
        int aux[r - l + 1];

        int p1 = l;
        int p2 = mid + 1;

        int k = 0;
        int res = 0;
        while (p1 <= mid && p2 <= r)
        {
            res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
            //求小和的关键步骤
            aux[k++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
        }
        while (p1 <= mid)
        {
            aux[k++] = arr[p1++];
        }
        while (p2 <= r)
        {
            aux[k++] = arr[p2++];
        }
        for (int i = l; i <= r; i++)
        {
            arr[i] = aux[i - l];
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 4, 2, 5};
    cout << Code_12_smallSum::mergeSort(arr, 5) << endl;
    getchar();
    return 0;
}
