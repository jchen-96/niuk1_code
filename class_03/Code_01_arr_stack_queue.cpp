#include <iostream>
#include <algorithm>

using namespace std;

class Array_Stack
{
  private:
    vector<int> vec;
    int size;

  public:
    Array_Stack(int initSize)
    {
        vec(initSize);
        this->size = 0;
    }
    int pop()
    {
        if (size == 0)
        {
            cout << "栈为空" << end;
            return -1;
        }
        else
        {
            return vec[--size];
        }
    }

    void push(int ele)
    {
        if (size == vec.size())
        {
            cout << "栈已经满" << endl;
            return;
        }
        else
        {
            vec[size++] = ele;
            return;
        }
    }
};

class array_queue
{
  private:
    vector<int> vec;
    int size;
    int first;
    int last;

  public:
    array_queue(int size)
    {
        vec(size);
        size = 0;
        first = 0;
        last = 0;
    }

    void push(int ele)
    {
        if (size == vec.size)
        {
            cout << "队列已满" << endl;
            return;
        }
        size++;
        vec[last] = ele;
        last = last == vec.size() - 1 ? 0 : last + 1;
    }
    int poll()
    {
        if (size == 0)
        {
            cout << "队列为空" << endl;
            return -1;
        }
        size--;
        int tmp = vec[first];
        first = first == vec.size - 1 ? 0 : first + 1;
    }
};