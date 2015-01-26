/*
作者:959547664@qq.com
题目:p1214 线段覆盖
*/

/*
遇到的最大的坑，没有考虑两个线段完全重合的情况，还有就是我的方法好像走了写弯路，比较好的思路是按起点排序，终点作为第二关键字，再比较
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool IsCross(int s1, int t1, int s2, int t2)
{
    if ((s1 > s2 && s1 < t2) || (t1 > s2 && t1 < t2)
        || (s2 > s1 && s2 < t1) || (t2 > s1 && t2 < t1)
        || (s1 == s2 && t1 == t2))
    {
        return true;
    }
    return false;
}

int GetCross(int (*lines)[2], bool * lineCross, int n)
{
    int nCross = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                lineCross[i * n + j] = false;
            }
            else
            {
                if (IsCross(lines[i][0], lines[i][1], lines[j][0], lines[j][1]))
                {
                    lineCross[i * n + j] = true;
                    lineCross[j * n + i] = true;
                    nCross += 1;
                }
                else
                {
                    lineCross[i * n + j] = false;
                    lineCross[j * n + i] = false;
                }
            }
        }
    }
    return nCross;
}

int GetMaxCross(bool * lineCross, int n)
{
    int nMax = 0;
    int nMaxIndex = -1;;
    for (int i = 0; i < n; i++)
    {
        int nCross = count(&lineCross[i * n], &lineCross[i * n] + n, true);
        if (nCross > nMax)
        {
            nMax = nCross;
            nMaxIndex = i;
        }
    }
    for (int j = 0; j < n; j++)
    {
        lineCross[nMaxIndex * n + j] = false;
        lineCross[j * n + nMaxIndex] = false;
    }
    return nMax;
}

int main()
{
    int n;
    cin >> n;
    int lines[n][2];
    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        lines[i][0] = a;
        lines[i][1] = b;
    }

    bool lineCross[n * n];
    int nTotalCross = GetCross(lines, &lineCross[0], n);
    int nLeftLineNum = n;

    while (nTotalCross > 0)
    {
        int nCrossNum = GetMaxCross(&lineCross[0], n);
        if (nCrossNum <= 0)
        {
            break;
        }
        nLeftLineNum -= 1;
        nTotalCross -= nCrossNum;
    }
    cout << nLeftLineNum;
    return 0;
}
