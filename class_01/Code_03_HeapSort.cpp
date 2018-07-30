#include <iostream>
#include <algorithm>

using namespace std;

//堆排序其实很简单

class Code_03_HeapSort
{
  public:
    static void heapSort(int *arr,int n)
    {
        if (arr == NULL || n == 0)
        {
            return;
        }
        //将数组转化成堆结构
        for (int i = 0; i < n; i++)
        {
            heapInsert(arr, i);
        }

        // 堆排序
        swap(arr[0], arr[--n]);
        while (n > 0)
        {
            //将数组重新调整为堆结构
            heapify(arr, n);
            swap(arr[0], arr[--n]);
        }
    }

    //几行代码就实现了shift up操作,优秀

    static void heapInsert(int *arr, int index)
    { //妙啊
        while (arr[index] > arr[(index - 1) / 2])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    static void heapify(int *arr, int len)
    {
        int index = 0;
        int left = index * 2 + 1;
        while (left < len)
        {
            int largest = (left + 1) < len && arr[left + 1] > arr[left] ? left + 1 : left;
            largest = arr[largest] > arr[index] ? largest : index;
            if (largest == index)
            {
                break;
            }
            swap(arr[largest], arr[index]);
            index = largest;
            left = index * 2 + 1;
        }
    }
};

int main()
{
    int arr[] = {5,4,3,2,1,10,12,-1,111};
    Code_03_HeapSort::heapSort(arr,9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << endl;
    }
    getchar();
    return 0;
}
