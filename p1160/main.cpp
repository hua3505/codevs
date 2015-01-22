/*
作者:959547664@qq.com
题目:p1160 蛇形矩阵
*/

#include <iostream>

using namespace std;

//void Fill(int *aSnake, int n)

int main()
{
    int n;
    cin >> n;
    int aSnake[n][n];

    int nLevel = n / 2;
    aSnake[nLevel][nLevel] = 1;
    int nNext = 2;
    for (int i = 1; i <= nLevel; i++)
    {
        //右
        aSnake[nLevel + i][nLevel + i - 1] = nNext++;
        //上
        for (int j = nLevel + i - 2; j >= nLevel - i; j--)
        {
            aSnake[nLevel + i][j] = nNext++;
        }
        //左
        for (int j = nLevel + i - 1; j >= nLevel - i; j--)
        {
            aSnake[j][nLevel - i] = nNext++;
        }
        //下
        for (int j = nLevel - i + 1; j <= nLevel + i; j++)
        {
            aSnake[nLevel - i][j] = nNext++;
        }
        //右
        for (int j = nLevel - i + 1; j <= nLevel + i; j++)
        {
            aSnake[j][nLevel + i] = nNext++;
        }
    }

    int nSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << aSnake[j][i] << ' ';
            if (i == j || i + j == n)
            {
                nSum += aSnake[j][i];
            }
        }
        cout << endl;
    }
    cout << nSum << endl;

    return 0;
}
