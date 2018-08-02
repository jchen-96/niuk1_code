#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

// 求解逆序对
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
            res+=arr[p1]>arr[p2]?(mid-p1+1):0;
            //逆序对
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
    int arr[] = {3,1,4,5,2};
    cout << Code_12_smallSum::mergeSort(arr, 5) << endl;
    getchar();
    return 0;
}
