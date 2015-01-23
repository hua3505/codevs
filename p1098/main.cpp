/*
作者:959547664@qq.com
题目:p1098 均分纸牌
*/

#include <iostream>

using namespace std;

int * g_aCards = NULL;
int nAverage = 0;

int Move(int nStartIndex, int nEndIndex)
{
    int Sum = 0;
    int times = 0;
    for (int i = nStartIndex; i <= nEndIndex; i++)
    {
        if (g_aCards[i] == nAverage)
        {
            nStartIndex = i + 1;
            continue;
        }
        break;
    }
    for (int i = nStartIndex; i <= nEndIndex; i++)
    {
        int sub = (Sum + g_aCards[i]) - (i - nStartIndex + 1) * nAverage;
        if (sub > 0)
        {
            g_aCards[i] -= sub;
            g_aCards[i + 1] += sub;
            times += 1;
            times += Move(i + 1, nEndIndex);
            sub = g_aCards[i] - nAverage;
            if (sub > 0)
            {
                g_aCards[i] -= sub;
                g_aCards[i - 1] += sub;
                times += 1;
                times += Move(nStartIndex, i - 1);
            }
            break;
        }
        if (sub == 0)
        {
            sub = g_aCards[i] - nAverage;
            g_aCards[i] -= sub;
            g_aCards[i - 1] += sub;
            times += 1;
            if (i - 1 != nStartIndex)
            {
                times += Move(nStartIndex, i - 1);
            }
            if (i != nEndIndex)
            {
                times += Move(i + 1, nEndIndex);
            }
            break;
        }
        Sum += g_aCards[i];
    }
    return times;
}

int Average(int * a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum / n;
}

int main()
{
    int nNum = 0;
    cin >> nNum;
    g_aCards = new int[nNum];
    for (int i = 0; i < nNum; i++)
    {
        cin >> g_aCards[i];
    }
    nAverage = Average(g_aCards, nNum);
    cout << Move(0, nNum - 1);
    return 0;
}
