#include <iostream>
#include <algorithm>
#include<vector>
#include<cstdio>

using namespace std;

// 将一个矩阵顺时针旋转90度，因为旋转，所以矩阵为n阶方阵
class Code_07_rotateMatrix
{
  public:
    static void rotate(vector<vector<int> > arr)
    {
        int hang = arr.size();
        int lie = arr[0].size();

        int sx = 0;
        int sy = 0;
        int endx = lie - 1;
        int endy = hang - 1;
        while (sx <= endx && sy <= endy)
        {
            rotate_circle(arr, sx++, sy++, endx--, endy--);
        }
    }

    static void rotate_circle(vector<vector<int> > &arr,int sx,int sy,int endx,int endy){
        for(int i=sx;i<endx;i++){
            int temp=arr[sy][i];
            arr[sy][i]=arr[endy-(i-sx)][sx];
            arr[endy-(i-sx)][sx]=arr[endy][endx-(i-sx)];
            arr[endy][endx-(i-sx)]=arr[sy+(i-sx)][endx];
            arr[sy+(i-sx)][endx]=temp;

            print(arr);

        }
    }

    static void print(vector<vector<int> > arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int> > arr;
    for (int i = 0; i < 4; i++)
    {
        arr.push_back(vector<int>(4,1));
        for (int j = 0; j < 4; j++)
        {
            arr[i][j]=(i * 4 + j + 1);
        }
    }
    Code_07_rotateMatrix::print(arr);
    Code_07_rotateMatrix::rotate(arr);
    getchar();
    return 0;
}