#include <iostream>
#include <algorithm>
#include <vector>
#include<cstdio>

using namespace std;

// 转圈圈打印数组

class Code_06_printMatrix
{
  public:
    static void print(vector<vector<int> > arr)
    {
        int hang = arr.size();
        int lie = arr[0].size();

        int sx = 0;
        int sy = 0;
        int endx = lie - 1;
        int endy = hang - 1;
        while (sx <= endx && sy <= endy)
        {
            print_circle(arr, sx++, sy++, endx--, endy--);
        }
    }

    static void print_circle(vector<vector<int> > arr, int sx, int sy, int endx, int endy)
    {
        for (int i = sx; i <= endx; i++)
        {
            cout << arr[sy][i]<<" ";
        }
        for (int i = sy + 1; i <= endy; i++)
        {
            cout << arr[i][endx]<<" ";
        }
        if (sy != endy)
        {
            for (int i = endx - 1; i >= sx; i--)
            {
                cout << arr[endy][i]<<" ";
            }
        }

        if (sx!=endx)
        {
            for (int i = endy - 1; i > sy; i--)
            {
                cout << arr[i][sx]<<" ";
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int> > arr;
    for (int i = 0; i < 4; i++)
    {
        arr.push_back(vector<int>(2,1));
        for (int j = 0; j < 2; j++)
        {
            arr[i][j]=(i * 2 + j + 1);
        }
    }
    Code_06_printMatrix::print(arr);
    getchar();
    return 0;
}
